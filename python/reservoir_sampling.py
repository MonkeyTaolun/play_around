import random
SAMPLE_COUNT = 1

# Force the value of the seed so the results are repeatable
random.seed(123)

sample_titles = []
for index, line in enumerate(open("wiki.txt")):
  print index, line
  # Generate the reservoir
  if index < SAMPLE_COUNT:
    sample_titles.append(line)
  else:                   
# Randomly replace elements in the reservoir
# with a decreasing probability.              
# Choose an integer between 0 and (index - 1) (inclusive)                
    r = random.randrange(index)                
    if r < SAMPLE_COUNT:                        
      sample_titles[r] = line

print sample_titles
