# PID Controller
[Check out final video](https://youtu.be/JwKJopKT5qc)

[//]: # (Image References)

[throttle_by_speed]: ./images/throttle_by_speed.png

### Goals
Implement a PID controller to maneuver the vehicle around the track!

### Description
I've used two PID controllers: one for angle and second for throttle control. Both tuned manually. I've extended ``` I ``` parameter: it has coefficient and range of integration

Total error calculated by angle controller going directly as angle correction factor.

Total error from throttle controller subtracting from this function:

<img src="https://raw.githubusercontent.com/kradio3/xakameyn/master/images/throttle_by_speed.png" height="300">
If car will go faster - throttle will smoothly close.

The final equation is:

![Throttle function](https://latex.codecogs.com/gif.latex?Throttle&space;=&space;\frac{5}{(0.05\cdot&space;speed&space;&plus;&space;0.8)}&space;-&space;1&space;-&space;E_{throttle})

### Effect of P, I, D components
- Proportional gain is kind of fast reaction to deviation from target. It works fine on low speeds. On high speeds car has high oscillations and cannot drive directly. So, I've suppressed it for high speeds.

- Derivative gain suppresses oscillations over target. I've set relatively high value for this parameter to achieve more stability on straight parts of track.

- Integral gain has effect on sharp turnes. It's not enough proportional and derivative gains to correct trajectory, therefore few previous CTEs will have the same sign. Summ of these previous CTEs will increase and integral component will add more value to correction. In case of oscillations previous CTEs will have different signs and summ of them will be close to zero. So it has low effect on straight parts of track.

### Parameter tuning
- Using proportional and derivative gains I've tried to stabilize car on straight parts of the track and parts with slight curves to achieve high speeds. Proportional gain has relatively small value, but derivative gain has high value to suppress oscillations.
- Using Integral gain and range of integrity I've tried to pass sharp turnes more aggressive. Range of integrity cannot be long, otherwise car has slow reaction to turn. From other hand it should be enough to accumulate CTEs with different signs in case of oscillations and reduce impact for oscillation correction.
