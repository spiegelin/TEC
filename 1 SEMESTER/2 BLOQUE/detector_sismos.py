import requests

url = "https://earthquake.usgs.gov/fdsnws/event/1/query?format=text&minmagnitude=5&limit=5"
response = requests.get(url)

text = str(response.content)
rows = text.split("\\n")
rows.pop()
for row in rows:
    data = row.split("|")
    print(data[-3], data[-1])

