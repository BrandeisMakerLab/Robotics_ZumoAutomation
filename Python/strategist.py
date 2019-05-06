#https://reqbin.com/
#https://www.tutorialspoint.com/listtutorial/Difference-between-GET-and-POST-method-in-HTTP/3916
#https://docs.python.org/2/library/simplehttpserver.html
#https://www.tutorialspoint.com/listtutorial/Difference-between-GET-and-POST-method-in-HTTP/3916

import requests
r = requests.get('http://129.64.183.82/')
r.text
print(r.text)
