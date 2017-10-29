# Cathode Ray Tube(CRT )
![ ](http://www.indiastudychannel.com/attachments/Resources/141259-25925-CRT-circuit-diagram.bmp  "CRT")
- A **beam of electrons (cathode rays)**, emitted by an electron gun, passes through focusing and deflection systems (using electromagnets) that direct the beam toward specified positions on the phosphor coated screen.
- The phosphor then emits a **small spot of light at each position contacted by the electron beam**.
- Because the light emitted by the phosphor fades very rapidly, some method is needed for maintaining the screen picture.
- **One way to keep the phosphor glowing is to redraw the picture** repeatedly by quickly **directing the electron beam back over the same points**. This type of display is called a ***refresh CRT.***
- When the electron hits the phosphor coating, they are stopped and their kinetic energy is absorbed by the phosphor.
- Part of the **beam energy** is converted by friction into heat energy, and the remainder **causes electrons in the phosphor atoms to move up to higher quantum-energy levels**.
- After a short time, the "excited phosphor electrons begin dropping back to their stable ground state, giving up their extra energy as small quantums of Light energy.

### Electron Beam generation
- The primary components of an electron gun in a CRT are the **heated metal cathode and a control grid**.
- **Heat is supplied to the cathode** by directing a current through a coil of wire, called the **filament**, inside the cylindrical cathode structure.
- In the vacuum inside the CRT envelope, the free, negatively charged **electrons are then accelerated** toward the phosphor coating **by a high positive voltage**.

### Intensity control
- Intensity of the electron beam is controlled by setting voltage levels on the control grid.
- **A high negative voltage** : will shut off the beam by repelling electrons and stopping them from passing through the small hole at the end of the control grid structure.
- **A smaller negative voltage** : decreases the number of electrons passing through.
- We **control the brightness** of a display by varying the voltage on the control grid.

### Focusing system
- Needed to force the electron beam to converge into a small spot as it strikes the phosphor. **Otherwise, the electrons would repel each other**, and the beam would spread out as it approaches the screen.
- Focusing is **accomplished with either electric or magnetic fields**.
- Electrostatic focusing is commonly used in television and computer graphics monitors.
- With electrostatic focusing, the electron beam passes through a **positively charged metal cylinder that forms an electrostatic lens**. The action of the electrostatic lens focuses the electron beam at the center of the screen.

### Deflection Sysytem
- Deflection of the electron beam can also be **controlled either with electric fields or with magnetic fields**.
- Cathode-ray tubes are now **commonly constructed with magnetic deflection coils mounted on the outside of the CRT
envelope**.
- **Two pairs** of coils are used, with the coils in each pair mounted on opposite sides of the neck of the CRT envelope
and Vertical deflection
	- One pair is mounted on the top and bottom of the neck **for Horizontal Deflection)**
	- and the other pair is mounted on opposite sides of the neck **(for Vertical Deflection)**
- The magnetic, field produced by each pair of coils results in a **transverse deflection force that is perpendicular both to the magnetic field and the travel of the electron beam. **
- The proper deflection amounts are attained by adjusting the current through the coils.

### Terminologies
- **Refresh Rate**
	- Rate at which the screen is refreshed
- **Persistence**
	-  Time taken by the emitted light to decay to 1/10th of its original intensity.
	- Lower persistence requires high refresh rates to maintain a picture without flicker.
	- Low persistence phosphor is useful for animation.
	- High persistence phosphor is useful for displaying complex static pictures.
- **Resolution**
	- The total no of points that can be displayed without overlap on a CRT.
	- Spot size depends on intensity. As more electrons are accelerated toward the phospher per second, the CRT beam diameter and the illuminated spot increase.
	- Also depends on type of phosphor and focusing and deflection systems.
- **Aspect Ratio**
	- The ratio of horizontal points to vertical points needed to produce equal length lines in both directions on the screen.

<br><br>

# Color CRT Monitors
- A CRT monitor displays color pictures by using a **combination of phosphors that emit different-colored light**. By combining the emitted light from the different phosphors, a range of colors can be generated.
- The two basic techniques for producing color displays with a CRT are :
- ***Beam-penetration method***
	- For displaying color pictures has been **used with random-scan monitors**.
	- Two layers of phosphor, usually red and green, are coated onto the inside of the CRT screen, and the **displayed color depends on how far the electron beam penetrates into the phosphor layers. **
	- **Slow electrons** : excites only the outer **red** layer.
	- **Very fast electrons** : penetrates through the red layer and excites the inner **green** layer.
	- **Intermediate beam speeds** : combinations of red and green light are emitted to show two additional colors, **orange** and b.
	- The speed of the electrons, and hence the screen color at any point, is **controlled by the beam-acceleration voltage**.
	- Has been an inexpensive way to produce color in random-scan monitors, but only four colors are possible, and the quality of pictures is not as good as with other methods.
- ***Shadow-mask method***
	- Commonly used in **raster-scan systems**
	- Produce a much wider range of colors.
	- A shadow-mask CRT has **three phosphor color dots at each pixel position**. One phosphor dot emits a **red** light, another emits a **green** light, and the third emits a **blue** light.
	- This type of CRT has **three electron guns, one for each color dot**, and a shadow-mask grid just behind the phosphor-coated screen.
	- The three electron beams are **deflected and focused as a group onto the shadow mask**, which contains a series of holes aligned with the phosphor-dot patterns. When the three beams pass through a hole in the shadow mask, they **activate a dot triangle**, which appears as a small color spot on the screen.
	- The phosphor dots in the triangles are arranged so that each electron beam can activate only its corresponding color dot when it passes through the shadow-mask
	![ ](http://nptel.ac.in/courses/Webcourse-contents/IIT-Delhi/Computer%20Aided%20Design%20&%20ManufacturingI/mod1/pics/pic02.jpg  "Shadow Mask")
	- The color we see depends on the amount of excitation of the red, green, and blue phosphors. A white (or gray) area is the result of activating all three dots with equal intensity.

<br><br>
# Direct-View Storage Tubes
- An alternative method for maintaining a screen image is to store the picture information inside the CRT instead of refreshing the screen.
- DVST stores the picture information as a charge distribution just behind the phosphor-coated screen.
- Two electron guns are used in a DVST
	- Primary gun used to store the picture pattern
	- Flood gun maintains the picture display
- Advantages
	- No refreshing is needed, complex pictures can be displayed without any flicker.
- Disadvantages
	- Modifying any part of the image requires redrawing the entire modified image
	- Erasing and redrawing process take several seconds for a complex picture.
	-No animation possible with DVST.

# Flat-Panel Displays

- ***Emissive Displays***
	- Devices that convert electrical energy into light. Ex : Plasma panels, thin-film electroluminescent
displays, and Light-emitting diodes.
	- Flat CRTs have also been devised, in which electron beams arts accelerated parallel to the screen, then deflected 90' to the screen. But flat CRTs have not proved to be as successful as other emissive devices.
- ***Nonemmissive displays***
	- Use optical effects to convert sunlight or light from some other source into graphics patterns.
	- Ex : liquid-crystal device and nonemissive displays.

___
# Display Methods
## Raster-Scan Displays

- The **most common type of graphics monitor** employing a CRT is the raster-scan display, based on television technology.
- In a raster-scan system, the **electron beam is swept across the screen, one row at a time from top to bottom**. As the electron beam moves across each row, the beam intensity is turned on and off to create a pattern of illuminated spots.
- Picture definition is stored in a memory area called the refresh buffer or frame buffer and holds the set of intensity values for all the screen points.
- Stored intensity values are then retrieved from the refresh buffer and "painted" on the screen one row (scan line) at a time.
- Each screen point is referred to as a **pixel** or pel *(shortened forms of picture element)*.
- The capability of a raster-scan system to store intensity information for each screen point makes it well suited for the realistic display of scenes containing subtle shading and color patterns.
- **Examples** : Home television sets and printers
-
### Intensity range
- In a simple black-and-white system, each screen point is either on or off, so only one bit per pixel is needed to control the intensity of screen positions.
- Additional bits are needed when color and intensity variations can be displayed.
- Up to 24 bits per pixel are included in high-quality systems, which can require severaI megabytes of storage for the frame buffer, depending on the resolution of the system.
- **Bitmap** :  Frame buffer of black-and-white system with one bit per pixeI
- **Pixmap** :  Frame buffer with multiple bits per pixel
- **Depth of buffer area** : Number of bits per pixel

### Refresh
- At the end of each scan line, the electron beam returns to the left side of the screen to begin displaying the next scan line.
- **Horizontal retrace** : The return of electron beam to the left of the screen, after refreshing each scan line.
- **Vertical retrace** : The return of electron beam to the top left comer of the screen to begin the next frame at the end of each frame.
- **Interlacing** :
	- On some raster-scan systems (and in TV sets), **each frame is displayed in two passes**.
	- In the **first pass**, the **beam sweeps across alternate scan lines** from top to bottom.
	- **After the vertical retrace**, the **beam sweeps out the remaining scan lines**.
	- Interlacing of the scan lines in this way allows us to see the entire screen displayed in one-half the time it would have taken to sweep across all the lines at once from top to bottom.
	- Primarily used with slower refreshing rates.
	- This is an **effective technique for avoiding flicker**, providing that adjacent scan lines contain similar display information.

## Random-Scan Displays
- Electron beam is directed **only to the parts of the screen where a picture is to be drawn**.
- Random-scan monitors **draw a picture one line** at a time and for this reason are also referred to as *vector displays* (or *stroke-writing* or *calligraphic diisplays*).
- The component lines of a picture can be drawn and refreshed by a random-scan system in any specified order. A **pen plotter** operates in a similar manner.
### Refresh
- Refresh rate depends on the number of lines to be displayed.
- Picture definition is now stored as a set of linedrawing commands in a n area of memory referred to as the refresh display file/ display list/ display program/ refresh buffer.
- To display a specified picture, the system cycles through the set of commands in the display file, drawing each component line in turn. After all line drawing commands have been processed, the system cycles back to the first line
command in the list.
- Random-scan displays are designed to draw all the component lines of a picture 30 to 60 times each second.
- Raster vs Random
	- Random-scan systems **cannot display realistic shaded scenes**.
	- Since picture definition is stored as a set of linedrawing instructions and not as a set of intensity values for all screen points, **vector displays generally have higher resolution than raster systems**.
	- Also, **vector displays produces smoother line drawings** because the CRT beam directly follows
	the line path.
	- Refresh time of Random-display is dependent on image complexity unlike Raster display.
	- Random-scan system's are generally costlier since decreasing memory costs have made Raster displays cheaper.
<br><br>
___
# Video Controller
![ ](https://image.slidesharecdn.com/rasterscansystem-130405095320-phpapp01/95/raster-scan-system-4-638.jpg?cb=1365155644  "Video Controller")

- Video controller **controls the operation of  display devices**.
- Frame buffer stores the drawing primitives in  terms of intensity values.
- Video Controller accesses the frame buffer to refresh the screen
- Two registers used to store screen pixel  coordinates : Register X and Register Y
- The  value stored in the frame buffer for the pixel position is retrieved and used to set the intensity values
- Basic video-controller refresh operations
	- For  each scanline
		- X is incremented from left to right.
		- X reset to 0 and Y decremented by 1 after last pixel of the scan line.
	- The process repeated till the bottom scan line
	- VC resets the registers to first pixel position to start refresh process.
	- To improve the refresh rate , multiple pixel intensities stored in separate register controls the beam intensity for adjacent pixel
