#Lab 8
## Relevent Information<br>
For this portion of the lab, the libraries that were made for lab 6 and lab 7 will be used, these are robotLibrary and Sensor library respectively.  With the sensors and motors being abstracted from this the main code for this lab, building the maze solving algorithm should become much simpler.<br>
## Maze Algorithm<br>
    for(;;)
    {
     moveForward(50,40) //This will have the robot always moving forward in a slightly right curve
     if(closeRightWall())
      {turnslightLeft();}
     if(closeFrontWall())
      {turnLeft();}
     }
The above algorithm should be able to successfully handle the maze that is used for the lab and should move out the A door.
