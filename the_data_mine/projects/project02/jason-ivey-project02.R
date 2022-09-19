#------------------------Q1------------------------
myDF <- read.csv("/anvil/projects/tdm/data/flights/subset/1995.csv", stringsAsFactors = TRUE)

# We want to use functions such as head, tail, dim, summary, str, class, to get a better understanding of our
# dataframe(DF)
class(myDF)
head(myDF)
tail(myDF)
dim(myDF)
summary(myDF)
str(myDF)
class(myDF)

# ### How many columns does this dataframe have?
#     29

# ### How many rows does this dataframe have? 
    
#     5327435

# ### What type/s of data are in this dataframe (example: numerical values, and/or text strings, etc.)

#     numerical values
#     text strings
#     booleans


#------------------------Q2------------------------
# A) This is a factor with 3 letter airport code 218 values
myairports <- myDF$Origin
summary(myairports)
head(myairports, n = 250) 

# B) The vector myairports contains all of the airports where flights departed in 1995. Print the first 250 of those
# airports. [Do not print all of the airports, because there are 5327435 such values!] How many of the first 250
# flights departed from O’Hare?
head(myairports, n = 250)
table(head(myairports, n = 250))["ORD"]

# How many flights departed by O’Hare altogether in 1995?
table(myairports)["ORD"]

#------------------------Q3------------------------

# How many flights departed from Indianapolis (IND) in 1995? How many flights landed there?
table(myDF$Origin)["IND"]
table(myDF$Dest)["IND"]
	# departed: 30792 arrived: 37103

# B) Consider the flight data from row 894 the data frame. What airport did it depart from? Where did it arrive?
myDF[894,]$Origin
myDF[894,]$Dest  
    # departed: PVD arrived: PHL

# C) How many flights have a distance of less than 200 miles?
longdistances = myDF$Distance[myDF$Distance < 200]
length(longdistances)  
    # 475141

#------------------------Q4------------------------
# A) Rank the airline companies (in the column myDF$UniqueCarrier) according to their popularity, i.e., 
#  according to the number of flights on each airline).
sort(table(myDF$UniqueCarrier), decreasing=TRUE)
	# DL     US     UA     WN     AA     NW     CO     TW     HP     AS

# B) Which are the three most popular airlines from 1995?
head(sort(table(myDF$UniqueCarrier), decreasing=TRUE), n = 3)
	# DL     US     UA 

# C) Now find the ten airplanes that had the most flights in 1995. List them in order, from most popular
#    to least popular. Do you notice anything unusual about the results?
head(sort(table(myDF$TailNum), decreasing=TRUE), n = 11)[2:11]
	# N67  N89  N83  N71 N103  N68 N102  N91  N59  N64 

#------------------------Q5------------------------

# Pick a column of data that you are interested in studying, or a question that you want answered. 
# Create either a plot, or a dotchart. Before making the plot, think about how many dots will be
# displayed on your plot or dotchart. If you try to display millions of dots, you might cause your
# Jupyter Lab session to freeze or crash. It is useful to think ahead and to consider how your plot
# might look, before you accidentally try to display millions of dots.

    # My Question: what is the ratio of inbound and outbound flights for the top 10 airports

library(data.table)

top_10_airport_arivals = head(sort(table(myDF$Dest), decreasing=TRUE), n=10)
top_10_airport_departures = head(sort(table(myDF$Origin), decreasing=TRUE), n=10)

ratio_dept_arrival = top_10_airport_arivals/top_10_airport_departures[rep(1, nrow(top_10_airport_arivals))]
dotchart(rev(ratio_dept_arrival))

# Descibe any patterns you may see in your plot or your dotchart. If there are none, that is okay,
# and you can just write "there seem to be no patterns.

    # We can see a clear pattern that more popular airports have more arrivals than departures.
    # This could be for many reasons but the underlying one is that more planes fly in than out of ORD. 