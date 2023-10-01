from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

chrome_driver_path="C:\\Python310\\chrome_driver\\chromedriver.exe"
driver=webdriver.Chrome(executable_path=chrome_driver_path)

driver.get('https://web.archive.org/web/20220120120408/https://secure-retreat-92358.herokuapp.com/')

first_name=driver.find_element('name','fName')
last_name=driver.find_element('name','lName')
email=driver.find_element('name','email')
first_name.send_keys('War')
# first_name.send_keys(Keys.TAB)
last_name.send_keys('Machine')
# last_name.send_keys(Keys.TAB)
email.send_keys('war@gmail.com')
email.send_keys(Keys.ENTER)



time.sleep(10)
driver.quit()