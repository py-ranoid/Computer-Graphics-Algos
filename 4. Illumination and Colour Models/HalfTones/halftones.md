#_HalfTones_#

###When is it used ? ###
* Output device has a limited intensity range, can increase the number of available intensities by combining multiple pixel positions into the display of each intensity value.

* The combined pixel positions are in the form of rectangular grids and are called  _**halftone patterns**_ or _**pixel patterns**_.

>###** A 2 by 2 pixel grid for five level intensity values (for bilevel systems.)**  

>![](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcREbRdCbpfsobgL4Rm6s3TfmFLQWfu9CTNFHPRSuYDnD0rCpCaD-Q)  

>###** A 3 by 3 pixel grid for ten level intensity values (bilevel systems.)**  

>![](https://www.cs.princeton.edu/courses/archive/fall95/cs426/lectures/04-Images/Ht2.gif)

* The **number of intensity levels** depends on how many pixels are included in the rectangular grids and **how many levels a system can display**
e.g: With n by n pixels for each grid, on a bilevel system (ON or OFF) n^2 + 1 levels can be represented.

> ** Pixel positions are chosen at each level so that the patterns approximate the increasing circle sizes used in halftone reproductions. **

>**'ON'** pixel positions are near the center of the grid for lower intensity levels and expand outward as the intensity level increases.

###Pixel Masks###
* For the 3 by 3 pixel grid shown above, the following **pixel mask** can be used to generate it. ( an nxn matrix)

> **The position number of the pixels is equivalent to the indices of the matrix.**
>** The numbers of the  matrix represent the intensity levels.**
<pre> 
8 	3	7
5	1	2
4	9	6
</pre>

* To display a particular intensity with **level number k**, turn on each pixel whose **position number** is **less than or equal to k**.

##Drawbacks of HalfTones and Avoiding Distortions.##
1. The **use of nxn pixel patterns reduces the resolution of the displayed picture by a factor of 1/n** along each of the x and y axes.
e.g. 512 by 512 screen area, reduced to 256 by 256 intensity points with 2 by 2 grid patterns.

2.	* Subgrid patterns become apparent as the grid size increases.
	* The grid size that can be used without distorting the intensity variations depends on the size of a displayed pixel.	
	> **INFERENCE : fewer intensity levels for systems with lower resolution and conversely.**

3.	* **Pixel grid patterns also constructed** to Minimize contouring and other visual effects not present in the original scene.
	* **Contouring minimized** by **evolving** each **successive grid pattern** from the **previous pattern**.
e.g. Form pattern at level 'k' by adding 'ON' position to grid pattern at level 'k-1'. 
* **Avoid symmetrical patterns** in the grid, as well as **isolated 'ON' pixels**.

5. **Halftone approximations can also be used** to increase the no. of intensity options on **systems** that are **capable of displaying more than two intensities per pixel**. 

	