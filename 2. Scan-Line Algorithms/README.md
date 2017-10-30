On raster systems, lines are plotted with pixels, and step sizes in the horizontal and vertical directions are constrained by pixel separations. That is, **we must "sample" a line at discrete positions** and **determine the nearest pixel to the line at each sampled position.**

Basic Line Formula :

	// Method 1
	for (x  = x1; x <= x2; x++) {
	   y = mx + c;
	   plot (x, y);
	}
Slow because there is a floating point multiplication. 
Break it down into adding the slope as a fraction dy/dx in a step wise manner;  what you need is a decision of when to increment y. Between degrees 0 and 45 the slope is a fraction less then 1. So basically as you go plotting Xs you add up the slopes until you get a value > 1. 
Thats when you increment y. so its like this:

# Digital Differential Analyzer (DDA)
We sample the line at unit intervals in one coordinate and determine corresponding integer values nearest the line path for the other coordinate.

	// Basic DDA for 0 < slope < 1
	for (x = x1, y = y1; x <= x2; x++) {
	   y = y + m;
	   plot (x,round(y))
	}

- Faster method for calculating pixel positions than the direct use of **Method 1**. 
- **Eliminates the multiplication** by making use of raster characteristics, so that **appropriate increments are applied in the x or y** direction to step to pixel positions along the line path. 
- The accumulation of roundoff error in successive additions of the floating-point increment, however, can cause the calculated pixel positions to drift away from the true line path for long line segments. 
- Furthermore, **the rounding operations and floating-point arithmetic in DDA are still time-consuming**. 
- We can improve the performance of the DDA algorithm by separating the increments m and l / m into integer and fractional parts so that all calculation are reduced to integer operations. 

# Bresenham's Line Algorithm

	dx = (x2 - x1)
	dy = (y2 - y1)
	for (x = x1, y = y1; x <= x2; x++) {
	   dy_sum += dy;
	   if (dy_sum > dx) {
	      y++;
	      dy_sum -= dx;
	   }
	   plot(x, y);
	}

The line would not be accurate and that is due to rounding differences. That can be fixed by initializing  dy_sum = dx/2 as shown here

	dx = (x2 - x1);
	dy = (y2 - y1);
	dy_sum = dx/2;
	for (x = x1, y = y1; x <= x2; x++) {
	   dy_sum += dy;
	   if (dy_sum > dx) {
	      y++;
	      dy_sum -= dx;
	   }
	   plot(x, y);
	}﻿ 