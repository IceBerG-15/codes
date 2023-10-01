from selenium import webdriver

chrome_driver_path="C:\\Python310\\chrome_driver\\chromedriver.exe"
driver=webdriver.Chrome(executable_path=chrome_driver_path)

driver.get('https://www.python.org/')
# price=driver.find_element('id','priceblock-ourprice')
# print(price.text)

# search_bar=driver.find_element('name','q')
# print(search_bar.get_attribute('placeholder'))

# logo=driver.find_element('class name','python-logo')
# print(logo.size)

# documentation_link=driver.find_element('css selector','.documentation-widget a')
# print(documentation_link.text)

# xpath=driver.find_element('xpath','//*[@id="site-map"]/div[2]/div/ul/li[3]/a')
# print(xpath.text)

menu_dates=driver.find_elements('css selector','.event-widget time')
menu_events=driver.find_elements('css selector','.event-widget li a')

events={}
for n in range(5):
    events[n]={
        'time': menu_dates[n].text,
        'name': menu_events[n].text
    }

print(events)
driver.quit()