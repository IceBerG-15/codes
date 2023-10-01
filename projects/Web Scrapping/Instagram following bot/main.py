from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.common.exceptions import ElementClickInterceptedException
import os
import time
from dotenv import load_dotenv

SIMILAR_ACCOUNT='leomessi'

class InstagramBot:
    def __init__(self):
        chrome_webdriver_path='C:\\Python310\\chrome_driver\\chromedriver.exe'
        self.driver=webdriver.Chrome(executable_path=chrome_webdriver_path)

    def login(self):
        load_dotenv('projects\Web Scrapping\Instagram following bot\.env')
        self.driver.get('https://www.instagram.com/')
        time.sleep(2)
        email=self.driver.find_element('xpath','//*[@id="loginForm"]/div/div[1]/div/label/input')
        password=self.driver.find_element('xpath','//*[@id="loginForm"]/div/div[2]/div/label/input')
        email.send_keys(os.getenv('EMAIL'))
        password.send_keys(os.getenv('PASSWORD'))
        password.send_keys(Keys.ENTER)


    def find_followers(self):
        time.sleep(5)
        self.driver.get(f"https://www.instagram.com/{SIMILAR_ACCOUNT}")

        time.sleep(2)
        followers = self.driver.find_element_by_xpath('//*[@id="react-root"]/section/main/div/header/section/ul/li[2]/a')
        followers.click()

        time.sleep(2)
        modal = self.driver.find_element_by_xpath('/html/body/div[4]/div/div/div[2]')
        for i in range(10):
            self.driver.execute_script("arguments[0].scrollTop = arguments[0].scrollHeight", modal)
            time.sleep(2)

    def follow(self):
        all_buttons = self.driver.find_elements_by_css_selector("li button")
        for button in all_buttons:
            try:
                button.click()
                time.sleep(1)
            except ElementClickInterceptedException:
                cancel_button = self.driver.find_element_by_xpath('/html/body/div[5]/div/div/div/div[3]/button[2]')
                cancel_button.click()
        


def main():
    insta=InstagramBot()
    insta.login()
    insta.find_follower()
    insta.follow()

if __name__ == '__main__':
    main()