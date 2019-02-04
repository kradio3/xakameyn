# PID Controller
[Check out final video](https://youtu.be/JwKJopKT5qc)

[//]: # (Image References)

[throttle_by_speed]: ./images/throttle_by_speed.png

### Goals
Implement a PID controller to maneuver the vehicle around the track!

### Description
I've used two PID controllers: one for angle and second for throttle control. Both tuned manually. I've extended ``I``` parameter: it has coefficient and range of integration

Total error calculated by angle controller going directly as angle correction factor.
Total error from throttle controller subtracting from this function:

<img src="https://raw.githubusercontent.com/kradio3/xakameyn/master/images/throttle_by_speed.png" height="400">
