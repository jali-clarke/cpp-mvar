# cpp-mvar
Mutexed variables

For those familiar with Haskell, an MVar is like a box which either has data
or does not.  It is primarily used for message passing between threads.  If an
MVar has data, taking data out will set its state to open.  If an MVar does not
have data, putting data in will set its state to closed.  If you try to take
data out from an open MVar, the thread will block until it is closed.  Similarly,
if you try to put data into a closed MVar, the thread will block until the MVar
is open.
