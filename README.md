# PID Controller
[Check out final video](https://www.youtube.com/watch?v=-EomKbKOcb4)

[//]: # (Image References)

[throttle_by_speed]: ./images/throttle_by_speed.png

### Goals
Implement a PID controller to maneuver the vehicle around the track!

### Description
I've used two PID controllers: one for angle and second for throttle control
![alt text][throttle_by_speed]


### Conclusion
It's more or less robust to pass more than 30 miles, but there are few points which could be improved:
- Prediction. Calculate values for slots after occupied slots according to difference of ego and observable cars speeds.
- Behavioral planner. Analyze more than one slice of belief. Means to check maneuvers with acceleration and deacceleration.
- Trajectory generator. Now it uses kind of fixed acceleration value -> calculate it dinamically according to difference between current and target speeds.
