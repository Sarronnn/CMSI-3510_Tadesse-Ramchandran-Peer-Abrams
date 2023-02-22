Homework 2 (Due on Wednesday of Week 9 - March 8th)

1. In the mutex-locking pseudocode of Figure 4.10 on page 111, there are two consecutive steps that remove the current thread from the runnable threads and then unlock the spinlock. Because spinlocks should be held as briefly as possible, we ought to consider whether these steps could be reversed, as shown in Figure 4.28 [on page 148]. Explain why reversing them would be a bad idea by giving an example sequence of events where the reversed version malfunctions.

  - Figure 4.28 is a buggy version of 4.10 because it contains a race condition. Meaning we are attempting to perform two or more operations at the same time. In Figure 4.10, the function removes the current thread from the runnable threads and then removes the spinlock, ensuring that only one thread can access the mutex at one time. But if figure 4.28 the spinlock is unlocked before the thread is removed from the runnable threads, which leaves enough time in between for two or more threads to acquire the mutex, which violates mutual exclusion.

2. Suppose the first three lines of the audit method in Figure 4.27 on page 144 were replaced by the following two lines:

```
int seatsRemaining = state.get().getSeatsRemaining();
int cashOnHand = state.get().getCashOnHand();
```
                    
Explain why this would be a bug.

  - This would be a bug since getting the seats remaining and the cash on hand happens at different points. By not taking a snapshot of all the data at one point first, you may take information between mutating operations. So cash on hand could be different than it was when you took seats remaining, thus they are inconsistent and your cash on hand may not match what it should be given the seats remaining you took.

3. **IN JAVA**: Write a test program in Java for the BoundedBuffer class of Figure 4.17 on page 119 of the textbook. ONLY WRITE THE TEST PROGRAM ~ DON'T MODIFY THE CODE FOR THIS ONE.

  - (DONE ON A SEPARATE FILE: BoundedBufferTest.java)

4. **IN JAVA**: Modify the BoundedBuffer class of Figure 4.17 [page 119] creating BoundedBuffer2.java. Make the new program call notifyAll() only when inserting into an empty buffer or retrieving from a full buffer. Test that the program still works using your test program from the previous exercise.

5. Suppose T1 writes new values into x and y and T2 reads the values of both x and y. Is it possible for T2 to see the old value of x but the new value of y? Answer this question three times: once assuming the use of two-phase locking, once assuming the read committed isolation level is used and is implemented with short read locks, and once assuming snapshot isolation. In each case, justify your answer.

  - Assuming two-phase locking:

  If two-phase locking is used, then T1 will acquire an exclusive lock on both x and y before writing new values. T2 will not be able to read x or y until T1 has released its locks. Therefore, T2 will not be able to see the old value of x or the new value of y until T1 has committed its changes. Thus, it is not possible for T2 to see the old value of x but the new value of y when using two-phase locking.

  - Assuming read committed isolation level with short read locks:

  If the read committed isolation level is used with short read locks, T2 will acquire a read lock on x and y before reading their values. If T1 has not yet committed its changes, then T2 will only be able to read the old values of x and y. However, if T1 has committed its changes, then T2 will be able to read the new values of both x and y. Therefore, it is possible for T2 to see the old value of x but the new value of y when using read committed isolation level with short read locks.

  - Assuming snapshot isolation:

  If snapshot isolation is used, T2 will read a consistent snapshot of the database that was taken at the start of its transaction. If T1 modifies the values of x and y after T2 has started, then those changes will not be visible to T2 because it is reading a snapshot that was taken before T1's changes. Therefore, it is not possible for T2 to see the old value of x but the new value of y when using snapshot isolation.


6. Assume a page size of 4 KB and the page mapping shown in Figure 6.10 on page 225. What are the virtual addresses of the first and last 4-byte words in page 6? What physical addresses do these translate into?

7. At the lower right of Figure 6.13 on page 236 are page numbers 1047552 and 1047553. Explain how these page numbers were calculated.

  - The physical page numbers are calculated based on the starting address of the file and the page size. In this example, the starting address of the file is 1046528, which is the starting address of the first page. The physical page number of the first page is then calculated by dividing the starting address by the page size: 1046528 / 4096 = 256. The physical page number of the second page is then simply 1 more than the physical page number of the first page: 256 + 1 = 257.

8. Write a program that loops many times, each time using an inner loop to access every 4096th element of a large array of bytes. Time how long your program takes per array access. Do this with varying array sizes. Are there any array sizes when the average time suddenly changes? Write a report in which you explain what you did, and the hardware and software system context in which you did it, carefully enough that someone could replicate your results.

  - I have this program run for arrays of sizes 1, 2, 4, 8, and 16 million, and as the function runs over larger arrays the average time per index seems to decrease. I do not know if the hardware that I have impacted this, but after 30-40 runs with diff results, the same trend occurs.

9. Figure 7.20 [page 324] contains a simple C program that loops three times, each time calling the fork() system call. Afterward it sleeps for 30 seconds. Compile and run this program, and while it is in its 30-second sleep, use the ps command in a second terminal window to get a listing of processes. How many processes are shown running the program? Explain by drawing a family tree of the processes, with one box for each process and a line connecting each (except the first one) to its parent.
