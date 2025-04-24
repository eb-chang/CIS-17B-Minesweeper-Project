# .bin file example
Please view the `bin_example.bin` file to see how data is stored!

* The first 4 bytes hold the number of users in a Record.
* The following bytes hold data for each user in the following format:
    * 4 bytes (int size) to hold n characters in username
    * n bytes to hold the username
    * 4 bytes (int size) to hold # wins for the user
    * 4 bytes (int size) to hold # wins for the user
    * 1 byte (bool size) to hold admin status for the user

Example:
```
02 00 00 00         <- total users (2 users)
06 00 00 00         <- # chars in first user's name (6 chars)
4A 6F 68 6E 6E 79   <- username ("Johnny")
05 00 00 00         <- Johnny's # wins (5)
03 00 00 00         <- Johnny's # losses (3)
00                  <- Johnny's admin status (not an admin)
05 00 00 00         <- # chars in second user's name (5 chars)
45 6D 69 6C 79      <- username ("Emily")
0B 00 00 00         <- Emily's # wins (11)
04 00 00 00         <- Emily's # losses (4)
01                  <- Emilys admin status (is an admin)
```
