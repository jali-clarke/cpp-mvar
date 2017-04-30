# cpp-mvar
Mutexed variables

For those familiar with Haskell, an MVar is like a box which either has data
or does not.  It is primarily used for message passing and synchronization between
threads.  If an MVar has data, taking data out will set its state to open.  If an
MVar does not have data, putting data in will set its state to closed.  If you try
to take data out from an open MVar, the thread will block until it is closed.
Similarly, if you try to put data into a closed MVar, the thread will block until
the MVar is open.

Run the demonstration program multiple times (~15 times maybe).  The unsynched version
may not always return 10000.  The synched version will (should) always return 10000.

Requires at least C++11.
