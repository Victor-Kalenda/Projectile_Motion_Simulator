# Projectile Motion Simulator
#### Video demo: <https://youtu.be/thJM0J1omLk>
#### Description:
archery.c takes numerous inputs about a bow and arrow (including wind_conditions),
and calculates the estimated angle at which the archer must aim up and left or
right to hit the center of the target. The purpose of this project was to learn
how to create mathematics based programs while also using the full capabilities
of a computer to calculate problems with more variables than equations. 

Information about the mathematical calculations and computational
methods can be found on "math.pdf". Information about the testing of archery.c
and this programs applicability can be found on "testing.pdf".

Numbers is a directory of all the individual functions that were used for
archery.c. Some function directories have multiple c files due to the fact that
there are multiple ways of calculating the same thing. As many methods as I have found
have been listed on each function directory. The functions that were used for archery.c
were the functions which I found used the least number of unnecessary additional
steps purely for better program design.

A lot of data was based on internet research and sources. The list below provides all
the references I based archery.c on.

- [The Density of air at STP](https://www.macinstruments.com/blog/what-is-the-density-of-air-at-stp/)
- [Optimal Launch Angle for an Arrow](https://www.scientificamerican.com/article/football-projectile-motion/)
- [Pi in C](https://stackoverflow.com/questions/43753758/whats-the-difference-between-m-pi-and-m-pi-2/43753803)
- [math.h Library](https://www.tutorialspoint.com/c_standard_library/math_h.htm)
- [The Extent of Acceptable Weather Conditions](https://www.nssl.noaa.gov/education/svrwx101/wind/)
- [Another Source for Acceptable Weather Conditions](https://www.weather.gov/pqr/wind)
- [Acceptable Drag Coefficients of an Arrow](https://www.capgo.com/FlyingSticks/info/arrowAerodynamics.html)
- [Elastic Potential Energy loss of a Bow](https://www.wired.com/2014/12/much-energy-bow-goes-kinetic-energy-arrow/)
- [Acceptable Poundages of a Bow](https://www.guinnessworldrecords.com/world-records/heaviest-longbow-draw-weight)
- "drag.pdf" is what archery.c bases it's drag coefficient on.
- "aerodynamics.pdf" confirms that the research for this drag coefficient is valid.

Conclusion

The loss in energy eminating from the tranfer of elastic potential energy to
kinetic energy is the most significant variable affecting how accurate the program 
is. Unfortunately, it is almost impossible to determine this loss in energy as
it is dependent on the tune of the bow in question. The smallest factors like 
the material the bow is made up of, the arrow spine, the plunger tension, and
even how the archer releases the string, all have an effect on how much energy 
is lost during the transfer. The energy loss for archery.c was described by the 
linear equation kinetic energy = 0.739 * elastic potenial energy + 0.286. In
reality, this equation is likely logarithmic. For these reasons, this program is 
inaccurate with a 16.255% error. Further development could reduce this number, 
however, more input would be required from the user.

