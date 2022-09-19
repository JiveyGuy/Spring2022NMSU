# Jason Ivey - Sep 18th 2022


#  888888ba                    oo                     dP   
#  88    `8b                                          88   
# a88aaaa8P' 88d888b. .d8888b. dP .d8888b. .d8888b. d8888P 
#  88        88'  `88 88'  `88 88 88ooood8 88'  `""   88   
#  88        88       88.  .88 88 88.  ... 88.  ...   88   
#  dP        dP       `88888P' 88 `88888P' `88888P'   dP   
#                              88                          
#                              dP                          
#  a8888a  dP   dP                                         
# d8' ..8b 88   88                                         
# 88 .P 88 88aaa88                                         
# 88 d' 88      88                                         
# Y8'' .8P      88                                         
#  Y8888P       dP     The Data Mine - TDM 10100  

#------------------------Q1------------------------                                  
                                                         
myDF <- read.csv(
	"/anvil/projects/tdm/data/craigslist/vehicles.csv",
	stringsAsFactors = TRUE
)
options(repr.matrix.max.cols=25, repr.matrix.max.rows=200)
options(jupyter.rich_display = F)
file.info("/anvil/projects/tdm/data/craigslist/vehicles.csv")$size
head(myDF)

### A) How many unique regions are there in total? Name 5 of the
# 		different regions that are included in this dataset.
length(table(myDF$region))
head(unique(myDF$region),n=5)

# 403 total with 5 of them being: mohave county, oregon coast,
# 	greenville / upstate, maine, south florida

### B) How many cars are manufactured in 2011 or afterwards,
# 		i.e., they are made in 2011 or newer?
sum(myDF$year >= 2011, na.rm=TRUE)
# 257000

### C.1) In what year was the oldest model manufactured?
head(sort(myDF$year), n=1)
# 1900

### C.2) In what year was the most recent model manufactured?
tail(sort(myDF$year), n=1)
# 2021

### C.3) In which year were the most cars manufactured?
head(sort(table(myDF$year), decreasing=TRUE), n=1)
# 2017 - 34592 

#------------------------Q2------------------------

###   Create a new column in your data.frame that is labeled
	# newflag which indicates if the vehicle for sale has been
	# labeled as like new. In other words, the column newflag
	# should be TRUE if the vehicle on that row is like new,
	# and FALSE otherwise.

myDF$newflag <- ifelse(myDF$condition == "like new", TRUE, FALSE)
table(myDF$newflag)


### Create a new column called pricecategory that is
# cheap for vehicles less than or equal to $1,500
# average for vehicles strictly more than $1,500 but less than or equal to $10,000
# expensive for vehicles strictly more than $10,000
myDF$pricecategory <- ifelse(
        myDF$price <= 1500, 
        "cheap",
        ifelse(
            myDF$price <= 10000, 
            "average",
            "expensive"
        )
)
table(myDF$pricecategory, useNA="always")

# How many cars are there in each of these three pricecategories ?
#  average    cheap expensive         NA
#  175158     48431    212260         0 

#------------------------Q3------------------------
