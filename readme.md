# Preface
This Project is a newbie-readable simulation for dtn on ns-3 environment, easy to use for research purples, supporting customed routing definition and scenario definition.
This project is highly inspirited by [Lakkakorpi](https://www.netlab.tkk.fi/tutkimus/dtn/ns/)
Read this teg-[paper](https://smartech.gatech.edu/bitstream/handle/1853/6492/GIT-CC-04-07.pdf?sequence=1&isAllowed=y) if you want know about TEG(time-expanded graph)
Read this [link](https://tools.ietf.org/html/draft-burleigh-dtnrg-cgr-00) if you want know about CGR

# Begin

* Install
  1. download source code
  2. cp /box/ns2mobilityhelper.cc to /ns-allineone-3.26/src/mobility, this file was modified and would help us parse 3d-motion
  3. modify your current_trace_file.tcl by your hand or by [bonnmotion](#A) or by ./create_trace_file.sh
  4. set node_number and simulation_time to jupytor and your-example.cc
        
        # in jupytor PreparSimulation
        T_max = 802                #change me !!!!!!!
        teg_slice_n = 802          #change me !!!!!!!

        // in ns3dtn-bit-your-example.cc
        node_number_ = 5;           // change me!!
        simulation_duration_ = 802;         // change me!!!

  5. run jupytor notebook animation to generate teg.txt, see [jupytor](#B)
  6. modify ns3dtn-bit-your-example.cc to set simulation settings, see [example-interface](#C)
  7. run ./build.sh to run simulation
  8. run jupytor notebook to parse result, to visualize your simulation result

# structure of this project

* editor tool : editor Vim do I use, if you are using YCM for code complete, remember add pull path of include to ~/.ycm_extra_config.py

* bonnmotion <a name="A"></a>
it is a software depending on java used to generate node trace files
we just need the **.ns_movements** file

* bonnmotion + ns2 + nam + nsg2.1
[ref](http://www.nsnam.com/2015/03/bonnmotion-mobile-scenario-generator.html) [ref](http://chandra-ns2.blogspot.com/2009/01/how-to-run-bonnmotion-for-ns-2.html)
[how to use this combo](https://www.slideshare.net/manasGaur1/bonn-motion-traffic-generation-and-nam)

* CMU setdest
The [author of that project](https://www.netlab.tkk.fi/tutkimus/dtn/ns/), Lakkakorpi used this CMU setdest program. [ref](http://www.isi.edu/nsnam/ns/tutorial/nsscript7.html)
But, we can't get 3d in "setdest", this problem aside, let's focus on how to use this setdest, in my machine, I did this "$sudo apt install ns2"
so I have the setdest in my "/usr/bin/setdest"

* ns3 example-interface
This file defines how your scenario structed, how your network configured.
Make sure that simulation time should be minus or equal to time of teg.txt.
Note that time-interval of two lines of teg.txt is exactly ** one second ** in real time, which was descripted in current_trace_file.tcl

* ns3 and ns3-dtn-bit module <a name="C"></a>
The main method for DtnApp is 1. checkbuffer - totransmit 2. receive bundle 3. sendhello - receive hello
We modify ns2-mobility-helper.cc, to support 3d-parse for us. you can find it at /box
Also, you can find image in /box
![ns3-dtn-bit module image][image01]

* jupyter and python-matplotlib <a name="B"></a>
there is one tutorial that I think may help you [ref](https://www.youtube.com/watch?v=HW29067qVWk&t=1568s)
This combo is used to make graph and paper, check /box/jupyter
if you want use jupyter yourself, install it on org-web, in China, you may not be able to download 0.5 G big file from the web.
you would need to install miniconda first, and install full-package from miniconda, that's the way I did.

* Acknoeledgement Annoucement, How does this model works.

    * transmit & send

            following graph are used to name variables in this project
            source_node         from_node               to_node           destination_node
                |                   |                       |                   |
                |                   |                       |                   |
                |                   |                       |                   |
                ()                  ()                      ()                  ()
                
                *-------------------------------------------------------------> *
                        this is called "send"
                *-----------------> * --------------------> * ----------------> *
                        this is called "transmition & retransmition"
                        note : "store and forward" is just semantic

            ack--->
            bundel---->     SocketSendDetail()
            anti-pkt----> 

            hello---->  CreateHelloBundleAndSendDetail()

    * If you want to modify code
        read code directly, everything is in content.

# TODO list

* <s>wireless max range </s> done by 
        wifiChannel.AddPropagationLoss ("ns3::RangePropagationLossModel",  
                "MaxRange", DoubleValue (4000.0));
* <s>note that ns2mobilityhelper only have ability to parse velocity 2d, extend it to support 3d </s> done by modify it, copy /box/ns2-mobilityhelp to src/mobility/helper to use it.
would support '$ns at $time $node setdest x2 y2 z2 speed' format, and this format only.
    
* <s>relative path </s> done by 
        config.txt
* <s>transmit session </s> done by
        transmit_assister_
* <s>time extented graph like that</s> [paper](https://smartech.gatech.edu/bitstream/handle/1853/6492/GIT-CC-04-07.pdf?sequence=1&isAllowed=y) done by
        Adob_do02 Adob_do03
- [ ] to work :(
- [x] to have a life
- [x] CGR, main feature, implement it!
- [ ] <s>running log was printed twice, more specifically NS_LOG_COMPONENT was printed out twice, it's a bug, fix it!</s> **we don't want to fix this bug** because jupyter parse script has depends on this bug
- [ ] relative path for script
- [x] last seen neighbor, should be 1 * Hello Interval or 2 * Hello Interval
- [x] give some senario, and give some result parse script
- [ ] unordered_map with tuple, bug fix
- [x] retransmission : For now we don't have local2neighbor retransmission. What we have is that, if one transmission session is not successed, this session would be remained, and reboot next time when routing decision is made by which transmission session producted had the same 'session value', where normally results to a new transmission session. Problem is that sprayandgood(), used for control transmit times, would block next time pkt check.
- [x] hello range is bigger than bundle range
- [x] routing decision bug

# Develpment Annoucement & Publish Log

* First edition, ns3dtnbit-1.0, we are going to read [this](https://www.netlab.tkk.fi/tutkimus/dtn/ns/), then rename variables methods and do code refactoring.
* Second edition, run a real example, and parse the log.
    * get trace file done 29.Feb
    * get jupyter to have an animation 5.Mar
        <s>fine, we got a idle loop, and I can't fix it</s>
        abstract example-interface
    * debug a bunch
        abstract routing-method interface
* Third edition, features and anything else for research.
* Fourth edition, ready to publish

[image01]: https://github.com/bit-oh-my-god/ns3-dtn-bit/tree/master/box/Diagram1.png
