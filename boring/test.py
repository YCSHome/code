from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time
import pyperclip

options = webdriver.ChromeOptions();

driver = webdriver.Chrome(options=options, executable_path='/opt/google/chrome/chromedriver')

cookies = {
    "UM_distinctid":"17f34e18c78338-02a81d41526c76-1b2b1204-1fa400-17f34e18c79d7",
    "_uid":"311721",
    "__client_id":"a44cb5c13f991e475bfd3c463b935ac4f09a6eca"
}
driver.get('http://www.luogu.com.cn/')
for cookie in cookies:
    driver.add_cookie({
        "domain":"luogu.com.cn",
        "name":cookie,
        "value":cookies[cookie],
        "path":"/",
        "expires":None
    })

driver.get('https://www.luogu.com.cn/user/311721#practice')

driver.implicitly_wait(1000)

t = driver.find_element_by_xpath('//*[@id="app"]/div[3]/main/div/div[2]/section[2]')

print(t[-1])

