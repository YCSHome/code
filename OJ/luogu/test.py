import time
from selenium import webdriver

options = webdriver.ChromeOptions()
driver = webdriver.Chrome(chrome_options=options, executable_path='/opt/google/chrome/chromedriver')
driver.get("https://www.baidu.com")
print('ok')
