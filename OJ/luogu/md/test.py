#! /bin/python3
import re
import sys
import urllib.request,urllib.error
import bs4

baseUrl = "https://www.luogu.com.cn/problem/"
savePath = "./"
maxn = 1050             #爬取最大题号

def main():
    if len(sys.argv) >= 2:
        for i in sys.argv:
            if (i != sys.argv[0]):
                html = getHTML(baseUrl + i)
                markdown = getMD(html)
                saveData(markdown, i + ".md")
    else:
        print("计划爬取到P{}".format(maxn))
        for i in range(1000,maxn+1):
            print("正在爬取P{}".format(i))
            html = getHTML(baseUrl + "P" + str(i))
            problemMD = getMD(html)
            saveData(problemMD,"P"+str(i)+".md")
            saveData(html, "P" + str(i) + ".html")
        print("爬取完毕")

def getHTML(url):
    headers = {
        "user-agent": "Mozilla / 5.0(Windows NT 10.0;Win64;x64) AppleWebKit / 537.36(KHTML, likeGecko) Chrome / 85.0.4183.121 Safari / 537.36"
    }
    request = urllib.request.Request(url = url,headers = headers)
    response = urllib.request.urlopen(request)
    html = response.read().decode('utf-8')
    return html

def getMD(html):
    bs = bs4.BeautifulSoup(html,"html.parser")
    core = bs.select("article")[0]
    md = str(core)
    md = re.sub("<h1>","# ",md)
    md = re.sub("<h2>","## ",md)
    md = re.sub("<h3>","#### ",md)
    md = re.sub("</?[a-zA-Z]+[^<>]*>","",md)
    return md

def saveData(data,filename):
    cfilename = savePath + filename
    file = open(cfilename,"w",encoding="utf-8")
    for d in data:
        file.writelines(d)
    file.close()

if __name__ == '__main__':
    print(sys.argv[0])
    main()



