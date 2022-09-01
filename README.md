# Reading Lines

Now that we remember how to C, let's implement a function to read files line by line, similar to `fgets(3)`. However, you'll be using the much lower-level `read(2)` *system call*.

`read()` takes three arguments:
* **fd** -- the *file descriptor* to read from. To get a file descriptor, use `open()`. For this assignment, `O_RDONLY` is sufficient for the *flags* parameter to `open()`.
* **buf** -- where data being read will be copied.
* **count** -- number of bytes to read. Since `read()` doesn't really recognize where lines start or end, you will tell it how many bytes to read at a time instead.

You'll build on this to implement your `lineread()` function.

Once that is complete, take it one step further by creating a `dynamic_lineread()` that can auto-allocate and resize a buffer (much like `getline(3)`). This will require dynamically re-allocating memory as needed.

You can use `make test` to test your implementations.
