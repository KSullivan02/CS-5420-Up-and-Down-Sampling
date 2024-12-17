---------Project 3: Upsampling and Downsampling Ver. 0.1.0---------
-----Usage-----
sample -h -s sampling_method -d depth -i intensity imagefile

-h: Displays usage and help page

-s: Sampling method used, 1 for pixel deletion and replication and 2 for pixel averaging and interpolation [default: 1]

-d: Depth is the number of levels used in the downsampling [default: 1]

-i: Intensity is the intensity of the levels [Default: 1, between 1 and 7]

@imagefile: The image to be sampled
---------------

----- Findings -----
The more intensity placed onto an image generally the cleaner the image came out in the end after being sampled.
Where as the more depth placed onto it it lost more quality
Generally I found using pixel averaging and interpolation to result in better quality after upsampling.


