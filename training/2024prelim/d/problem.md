Problem D
Dr Carboi
Time limit: 1 second
Dr Carboi loves toy cars and racing toy cars from his collection on his circular race track. But Dr Carboi has a
problem — he spent all his pocket money on toy cars and now he has too many toy cars and only one race track!
If he puts all of his cars at the start of the track at once, they will
crash into each other. Dr Carboi knows what to do though: he will
stagger the starting times. He will place the first car on the track then
wait exactly G seconds before placing the next car on the track, and so
on, waiting exactly G seconds between placing each car at the start of
the track. Cars immediately start driving once they are placed on the
track.
The track is circular, so the cars will go round and round the track
as they do laps. Dr Carboi doesn’t want the first car hitting his fingers
when it comes back around to start its next lap, so he won’t place any
more cars on the track at or after it finishes its first lap. Dr Carboi has
worked out the number of seconds, Ti, that it takes for each of his R cars
to do one lap around the track, and a car is considered to have finished
a lap exactly Ti seconds after it started the lap.
The track also only has one lane, so cars cannot pass each other. If
a car catches up with another car, it will crash into it and Dr Carboi will
be sad. A car P crashes into another car Q if it started a lap after Q did but would finish the lap before or at the
same time that Q finishes its lap.
Dr Carboi has realised that with these constraints he may not be able to race all his cars in one go, so he needs
to settle for only racing some of them. If he has to choose only some of his cars, he wants to race only his fastest
(and hence coolest) cars from his collection for L laps. That is, if he races K cars, then he will pick the top K
fastest cars. Note that lower Ti means faster, and he doesn’t care about how ties for Ti are broken.
Just after a car finishes its last lap, Dr Carboi will scoop it up off the track away from danger. Up until then,
including the instant it finishes its last lap, it may still crash into other cars.
Dr Carboi wants to know K, the maximum number of toy cars he can race on the track at once for L laps,
without any cars crashing into each other and using his K fastest cars. Dr Carboi can place the K cars on the track
in any order (staggering their start times by G seconds, as described above) and they all must be placed before the
first car finishes its first lap to avoid it hitting his fingers.
Input
The first line contains three integers, L (2 ≤ L ≤ 10) which is the number of laps in the race, G (1 ≤ G ≤ 1000)
which is the number of seconds Dr Carboi waits between placing each toy car, and R (1 ≤ R ≤ 2000) which is
the number of toy cars.
The following R lines each contain a single integer Ti (1 ≤ Ti ≤ 2 × 107) which is the number of seconds for
the ith car to do one lap of the track.
Output
Display the maximum number of cars Dr Carboi can race.