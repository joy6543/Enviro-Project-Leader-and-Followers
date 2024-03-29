# Enviro-Project-Leader-and-Followers
#### EEP 520A: Final Project by Somnath Mukherjee

## Goal of the Project:

STEP 1: To create a Leader robot that moves and wanders in the arena in a loop.

STEP 2: Add a Follower robot that follows the Leader robot at a respectable distance.

STEP 3: Add more Follower robots. All of them follows the Leader's path.

STEP 4: The entire pack moves around the arena. The patterns are as follows:

---> When in a straight line, all the Follower robots traverse in a straight manner.

---> When Leader takes a turn at corners, the Follower robots flock together while tracking the Leader.

---> After that, all the Follower robots follow the Leader in a straight line (in every angles)..and so on.

INFO: Leader Robot: Lightorange box with a striker, Follower Robots: Blue, Green, Red, and Yellow colored boxes.

## Key Challenges:

1) I got introduced to ENVIRO during this course. It was a challenge for me to understand the methods, classses and objects and their usage. 

2) It took time to go through the examples and then incorporate the required ones. Also, I started with 'State Machines' for the Leader robot, but ended up using 'Process' model for both the Leader and Follower robots. 

3) The use of 'State Machines' made the coding easier for me by using the ```init()``` and ```update()``` methods. Also, it helped me use the ```emit``` and ```watch``` events between the Leader and Follower robots.

4) Leader was getting stuck at corners. Played with the ```sensor_value()``` and made the Leader turn at nearing distances of <70.

5) When the Leader was alone it was a different situation- it moved freely. But as I introduced the Follower robot/s there were many issues:

i) Follower not going behind the Leader and moving in different directions. Fixed that by using: ```find_agent()``` and ```attach_to()``` methods.

ii) Now I added other Follower robots and they started pushing and holding the Leader robot at edges/ corners. This was happening as the collective power of the Follower robots was exceeding that of the Leader robot. After numerous trials by modifying the .json files of both Leader and Follower robots- by trying different shapes, friction parameters, sensor values as well the mass, the issues got resolved.

iii) Finally, during multiple trials, the Leader robot was getting stuck in between the Follower robots. Fixed that by modifying the forward and rotation velocities using the ```track_velocity``` method. 

## How to install and run the code:

In my git repo, the project can be downloaded by navigating to the Green <>Code button and choosing any step from the dropdown:

Use the HTTPS command to clone: https://github.com/joy6543/Enviro-Project-Leader-and-Followers.git

Use the SSH command to clone: git@github.com:joy6543/Enviro-Project-Leader-and-Followers.git

Download my repo completely using the Download Zip Button.

Open with GitHub Desktop application.

## How to run and/or use the project:

1) Assuming that docker is already installed. Run the following command on Command prompt/ Terminal: 

```docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.61 bash```

In place of ```$PWD``` use the local address where you downloaded the code. 

(For eg: ```docker run -p80:80 -p8765:8765 -v /c/Users/mukhe/desktop/uw/enviro-project-leader-and-followers:/source -it klavins/enviro:v1.61 bash```)

2) Open ```http://localhost``` on the browser, to see the program running.

3) And then type in the Command prompt/ Terminal:

4) ```ls``` : To check the files in the folder

5) ```cd Project``` : Enter into the folder, here Project, containing the ```config.json``` and required files

6) ```ls``` : To ensure if all the required files are present

7) ```esm start``` : To start the Enviro environment (check the browser for this message: ```Enviro Error: No connection. Is the server running? See here for help.```)

8) ```make``` (then press ENTER)

9) ```enviro``` (then press ENTER)

10) Check the ```http://localhost``` and the program execution can be viewed.

11) You can press ```Ctrl-C``` (in Command prompt/ Terminal) to stop the Enviro server.

12) Run couple of times (type ```make``` (ENTER) and then ```enviro``` (ENTER)), if minor glitches are encountered.

## Acknowedgements to all sources of information or code used:

1) Course GitHub repo README examples on ENVIRO for week 9 (https://github.com/sosper30/eep520/tree/main)

2) Course GitHub repo example codes on ENVIRO for week 9 & 10 (https://github.com/sosper30/eep520/tree/main)

3) Prof. Klavins Github repo README file for understanding and implementing the methods (https://github.com/klavinslab/enviro/blob/master/README.md)

4) Prof. Klavins coded examples (https://github.com/klavinslab/enviro/tree/master/examples).

#### Thank You and Enjoy the navigating Robots!
