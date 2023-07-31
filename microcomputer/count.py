from selenium import webdriver

browser = webdriver.Chrome()

def main():
    browser.maximize_window()

    url = 'https://bkcat.cn/Hall_of_Fame.mp3'
    browser.get(url)

if __name__ == '__main__':
    main()
    input("Press Enter to close the browser...")
    browser.quit()
