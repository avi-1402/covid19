# covid19
A short program to check the number of testing kits required to check for covid 19 in a town where some cases of covid 19 were reported.
Given a town population, percentage of service providers there and the number of infected people found, we are giving the probable number of testing kits that the town must acquire from the government.
According to different scenarios of social distancing protocols that may have been followed, differnt results will be generated.
We are assuming that in case no social distancing is followed, a person on average comes in contact with 20 people on a daily basis, but in case of a service provider the count may be larger.
Using adjacency matrix and a BFS algorithm we are building a chain of people that may be covid positive, and returning their count.
