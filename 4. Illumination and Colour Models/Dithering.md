#Dithering#

####Define ?
* **refers to techniques for approximating halftones without reducing resolution, as pixel-grid patterns do.**

* Random values added to pixel intensities to break up contours are often referred to as **'dither noise'**.

##_Different Methods._

##1. Ordered-Dither Method : 

* Generate intensity variations with a **one-to-one mapping** of points in a scene to the **display pixels**.

* To generate n^2 intensity levels, we set up an **n by n matrix, Dn.**

* The **elements** of Dn are in the **range 0 to n^2 - 1** (distinct).
e.g.  
><pre>D2 =
3 	1
0	2
</pre>
><pre>D3 =
7	2	6
4	0	1
3	8	5
</pre>

* For a bilevel system, we then **determine display intensity** values by **comparing the input intensities** to the **matrix elements**.

* Each input intensity is first scaled to the range **0<=I(intensity)<=n^2**.

* If the intensity I, is to be applied to screen position (x,y), we calculate row and column numbers for the dither matrix as
	** i=(x mod n)+1 and j=(y mod n)+1.**

* If **I > Dn(i,j) then turn on the pixel at position (x,y)**, Otherwise do not turn on.

* Order dither produces constant-intensity areas identical to those generated with pixel-grid patterns when the values of the matrix elements correspond to the grid mask.

* **Variations from the pixel-grid displays occur at boundaries of the intensity levels.**