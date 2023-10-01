from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time         #using time.sleep to let the pages load and then do other stuff
import os
from dotenv import load_dotenv

class InternetSpeedTwitterBot:
    def __init__(self):
        chrome_driver_path="C:\\Python310\\chrome_driver\\chromedriver.exe"
        self.driver=webdriver.Chrome(executable_path=chrome_driver_path)
        self.result_down=0
        self.result_up=0

    def get_internet_speed(self):
        self.driver.get('https://www.speedtest.net/')

        time.sleep(2)
        go_button = self.driver.find_element('xpath','//*[@id="container"]/div/div[3]/div/div/div/div[2]/div[3]/div[1]/a/span[4]')
        go_button.click()

        time.sleep(60)

        self.result_down=self.driver.find_element('xpath','//*[@id="container"]/div/div[3]/div/div/div/div[2]/div[3]/div[3]/div/div[3]/div/div/div[2]/div[1]/div[1]/div/div[2]/span')
        print('download speed- ',self.result_down.text)

        self.result_up=self.driver.find_element('xpath','//*[@id="container"]/div/div[3]/div/div/div/div[2]/div[3]/div[3]/div/div[3]/div/div/div[2]/div[1]/div[2]/div/div[2]/span')
        print('upload speed- ',self.result_up.text)



    def Tweet_at_provider(self):
        load_dotenv('projects\Web Scrapping\Twitter bot\.env')

        msg=f'Hey, Internet Provider, why is my internet speed {self.result_down}down/{self.result_up}up, when I pay for 150 down/100 up? '

        self.driver.get('https://twitter.com/i/flow/login')
        time.sleep(3)

        email_input=self.driver.find_element('xpath','//*[@id="layers"]/div/div/div/div/div/div/div[2]/div[2]/div/div/div[2]/div[2]/div/div/div/div[5]/label/div/div[2]/div/input')
        email_input.send_keys(os.getenv('EMAIL'))
        email_input.send_keys(Keys.ENTER)

        time.sleep(2)
        pass_input=self.driver.find_element('xpath','//*[@id="layers"]/div/div/div/div/div/div/div[2]/div[2]/div/div/div[2]/div[2]/div[1]/div/div/div[3]/div/label/div/div[2]/div[1]/input')
        pass_input.send_keys(os.getenv('PASS'))
        # pass_input.send_keys(Keys.ENTER)
        
        self.driver.quit()



def main():
    tweet=InternetSpeedTwitterBot()
    tweet.get_internet_speed()                          #getting realtime internet speed
    if tweet.result_down<200 or tweet.result_up<100:    #comapring above with claimed speed
        tweet.Tweet_at_provider()

if __name__ == '__main__':
    main()
