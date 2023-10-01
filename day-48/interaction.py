from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

chrome_driver_path="C:\\Python310\\chrome_driver\\chromedriver.exe"
driver=webdriver.Chrome(executable_path=chrome_driver_path)

driver.get('https://en.wikipedia.org/wiki/Main_Page')

article_no=driver.find_element('xpath','//*[@id="articlecount"]/a[1]')
# print(article_no.text)
# article_no.click()

search_bar=driver.find_element('name','search')
search_bar.send_keys('python')
search_bar.send_keys(Keys.ENTER)


time.sleep(10)
driver.quit()