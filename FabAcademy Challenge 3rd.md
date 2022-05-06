*3rd Fabacademy Challenge**
===============


by [Rei Terauchi](https://terauchi-rei.github.io/mdefweb/) & [Emilio Smith](https://emiliosmith.github.io/mdef_emilio2/)

## Objective

How can we activate participation in a community
Using data to encourage an activity that benefit all the members

In a community based project, we have to encourage the participation of people, we have to design the inputs that motivate people to integrate and participate for the good of the community.
When we talk about compost making, we are lacking inputs to know if we are doing well or not if we are not used to work with soil and plants.
With that in mind, it is needed to design something that can give a lecture and create an output of information that could be available for a community and in that way activate the participation.
We intend to use this concept to design an interaction between sensors that can be connected to the soil or the compost in order to connect to the people in the community and have a social action and integration in the task that benefits all.

## Process

1. Humidity sensor sharing data
2. Soil Mixer connected to wifi/moving with heat generated energy

![](/images/S__6307842.jpg)
![](/fimages/protocol.jpeg)
![](/images/ref.jpeg)

# Humidity sensor

This time we tried to use the humidity sensor connected to wifi, in order to make your phone showing the percentage of humidity whenever you connect to the page.  It detects the humidity at every certain time that you control by arduino.
First, we have this water pump kit that we wanted to use in order to automatically control the humidity of plants/compost.

![](/images/kit.jpeg)

In theory, if we have this on, we will not let the plants die. We killed some plants when we left them over the holidays.

![](/images/S__6438935.jpg)

We first planned to have this dream image.
Somehow we wanted to pursue the way that we share collected  data community wise since we are engaged in this community garden in Poblenou.
Emilio tried hard to control this humidity sensor using an arduino IDE for the CPU we had of ESP32. 
So many problems happened through this process because the sensor gives the random numbers which indicate the voltage that sensor senses. So it was hard to convert them into the number of percentages. 

![](/images/S__6438937.jpg)
![](/images/S__6438947.jpg)

Also, the percentage was somehow backward of the actual number. So it was also hard to fix it how it is supposed to be.
In the end, it is connected to the rechargeable battery to be on its own so it doesn't have to be connected to a computer. With a 3d printed case for both battery and the CPU, it can be embedded in the soil of plants/compost.
While printing, Emilio worked on the Html to visualize the percentage in a nicer way to show information.

![](/images/html.jpeg)
![](/images/pcb.jpeg)
![](/images/test2.jpeg)
![](/images/test5.jpeg)
![](/images/plants.jpeg)

!! It is still in the process. Now printing.

![](/images/case.jpeg)
 
# Soil Mixer
Firstly we wanted to use peltiers to generate electricity with the heat of compost. So we  tried how it works and at which degrees of temperature that it can generate electricity. It is called waste heat power generation.

![](/images/coffeee.jpeg)
![](/images/peltier.jpeg)

We first tried with the motor, heating up the peltier with a heat gun, also checking the temperature with a thermometer.
It looks like it(one peltier) can move the motor at 60 degrees. 

![](/images/motor.gif)

While leaving some soil outside under sun with the acrylic sphere cover, it reaches 35 degrees or more. In theory, the website says that it can reach up to 65 degrees.

![](/images/S__6438933.jpg)
![](/images/compost.jpeg)

The peltier I got was this.Max 12 volts and 6A.
Then I tried to move the water pump that requires 3 or 5 volts. I connected two peltiers to generate electricity that must be enough to turn on the water pump.
Though it didn't work. So there needs to be more voltage or amperage. Rei checked up how much the water pump requires to move, then there should be 3v with amperage of or 1.5v with more than 200 amperage. 
Rei tried to connect peltiers in both parallel / linear to solve this but it didn't move.
In the end, with only 2 peltiers, it is impossible to generate enough energy to make a water pump work. So Rei decided not to use the water pump this time.  Victor introduced  the Stirling engine which we want to try next time.

Peltiers moved the motor, so we decided to use the motor for the soil mixer. So probably we can control the compost mixer with its heat.
We first set up this breadboard work, for making a motor work with the light so we can later change the protocol to make it work with the heat and with the peltier.

![](/images/S__6438939.jpg)
![](/images/mixer.jpeg)
![](/images/S__6438932_0.jpg)


Though, somehow it didn’t work even with the computer. So we are stuck here.

![](/images/arduino.jpeg)

At one time, we 3d printed a mixer propeller so it can be attached to the motor.


## Problems
-the sensor was not stable. We struggled to figure out the sensor was properly working.
-it was the first time using peltiers to work, and we didn't find any examples using peltiers for arduino projects. Probably it is not ideal to use for electricity. 
-No time to fabricate the artifacts.
-Arduino problems with Mac computers?


## Future Development
We will try to finish the artifacts as soon as we figure it out. First, we will finish the sensor embedded in the compost and will have the soil mixer ready.
For the soil mixer, we want to connect it to the phone via wifi so it is available for controlling on/off online.
Then we want to take the next step of using peltiers to generate electricity, for moving soil mixers. Or we can challenge the other artifacts that generate energy with sunlight, like stirling engines. Also if there is time, we can use water pumps to work with the compost heat so we can create an automated self-circular compost bin with some data shared online in the community. 








