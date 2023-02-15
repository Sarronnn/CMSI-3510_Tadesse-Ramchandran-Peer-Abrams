# Operating Systems Preliminary Design

1.1 – Description of modification/addition to Linux

Linux has the functions `mkdir` (Make Directory) and `touch` apart of its kernel. `mkdir` creates a new empty directory whose name is defined by path. The file permission bits in mode are modified by the file creation mask of the job and then used to set the file permission bits of the directory being created. The touch command's primary function is to modify a timestamp. Commonly, the utility is used for file creation, although this is not its primary function. The terminal program can change the modification and access time for any given file. The touch command creates a file only if the file doesn't already exist. The modification that we intend to make is to combine these two commands into one that has the utilities of both. This will make a directory and create files in said directory.

1.2 – Rationale as to why this is a good idea, or what the good points of it are

This idea came from setting up github repositories. Since you can't push empty directories to github, we always put a blank file inside folders so they show up on GitHub. It would be nice to automate this process with a single command. This would be a good idea since it simplifies what is usually a two part process.

1.3 – Preliminary list of [possible] Linux modules that will be modified/affected

We may modify or reference the modules for `mkdir` and `touch`.

1.4 – Preliminary list of any new modules that you will produce [or 'Not Applicable' if there are none]

We will add a module for our command `mkfid` [make file in directory].
