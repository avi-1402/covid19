# covid19
*A short program to check the number of testing kits required to check for covid 19 in a town where some cases of covid 19 were reported.*

**Project Description**
1. Given a town population, percentage of service providers and the number of infected people found, we receive the probable number of testing kits that the town must acquire from the government as output.
2. According to different scenarios of social distancing protocols that may have been followed, different results will be generated.
4. Using adjacency matrix and a BFS algorithm we are building a chain of people that may be covid positive, and returning their count.

**Assumptions Taken**
1. We are assuming that in case no social distancing is followed, a person on average comes in contact with 20 people on a daily basis.
2. A service provider comes in contact with a larger number of people according to the percentage of service providers in the town.
3. The scenarios taken into account are -
   * No social distancing
   * 33% social distancing
   * 50% social distancing
   * Reduced contact with service providers with 50% social distancing

**Instructions to run**
* The code is written in C. The object file to run the project on terminal is also present in the project2 folder.
* Basic instructions to run the program are in the readme file available in project2 folder.
