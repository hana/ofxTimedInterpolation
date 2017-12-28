# ofxTimedInterpolation

This addon enables you to get the ratio of the elapsed time to the duration time.  

## USAGE
1.Instantiation ofxTimedInterpolation  
`ofxTimedInterpolation timedInterpolation`

2.Just Bang with the duration  
`timedInterpolation.bang(1000)`

3.Then you will get the ratio of elapsed time to the duration  
`float ratio = timedInterpolation.get() //if reached, the value is 1.0`

For more details, please check the example.
