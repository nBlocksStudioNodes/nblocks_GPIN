# n-Blocks Studio GPI Node

This node is a **G**eneral **P**urpose **IN**nput : it passes the `pinIn` to the Node output variable with no changes, in the following frame.  
The difference from GPI Node is
*  The `pinIn` mode is configurable with Parameter `modeString` as:
   *  PullUp
   *  PullDown
   *  PullNone
   *  OpenDrain

The underneath mbed API is `DigitalIn`  
Based on GPI Node
Author: Nikos Chalikias