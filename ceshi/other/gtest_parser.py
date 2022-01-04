import json
import sys
from jinja2 import FileSystemLoader, Environment
import xml.etree.ElementTree as ET
import operator
import base64
import datetime
import shutil
import os
# Constants
TEMPLATE_FILE = "gtest_template.html"
OUTPUT_FILE = "gtest_output.html"

def process_input(input_file):
    """ Processes the input file.
        Will return a JSON object to be used by the HTML parser.
        If the file is in XML format it will be turned into a JSON object.
    """

    data = None

    with open(input_file) as gtest_json:
        if input_file.endswith('.json'):
            data = json.load(gtest_json)
        elif input_file.endswith('.xml'):
            # Need to turn the XML into the same format as the JSON
            data = process_xml(gtest_json)
        else:
            print("Unknown file type.")
            return

    return data

def process_time(milleSeconds):
  if milleSeconds<1000:
    strTime = str(round(milleSeconds,4))+'ms'
  elif milleSeconds<60*1000:
    strTime = str(round(milleSeconds/1000,2))+'seconds'
  else:
    strTime = str(round(milleSeconds/(60*1000),2))+'minutes'
  return strTime

def readPicData(filename):
    try:
        f = open(filename,"rb")
        text = f.read()
        f.close()
        content = base64.b64encode(text)
        content = content.decode()
        print("binary=", content)
        return content
    except FileNotFoundError:
        print("no such file")
    

def process_xml(xml):
    """ Processes the XML file.
        Will return a JSON object that matches that created by GTEST.
    """

    tree = ET.parse(xml)
    root = tree.getroot()
    overviewName = root.attrib['name']
    overviewTests = int(root.attrib['tests'])
    overviewFailed = int(root.attrib['failures'])
    overviewDisabled = int(root.attrib['disabled'])
    overviewBeginTime = root.attrib['starttimestamp']
    overviewEndTime = root.attrib['endtimestamp']
    overviewServer   = root.attrib['server']
    overviewTitle   = root.attrib['title']
    overviewUser   = root.attrib['user']
    overviewDuration = process_time(float(root.attrib['time'])) #str(round(float(root.attrib['time'])/1000/60,2))+'minutes'
    data = {
        'name': overviewName,
        'tests': overviewTests,
        'failures': overviewFailed,
		'disabled': overviewDisabled,
        'begintime':overviewBeginTime,
        'endtime':overviewEndTime,
        'title':overviewTitle,
        'user':overviewUser,
        'server':overviewServer,
        'duration':overviewDuration,
        'testsuites': [],
        'slowestsuites': [],
        'failedsuites':[],
        'classes':0,
        'slowestCount':0
    }
    classesCount = 0
    allTempTestCase = []
    for child in root:
        classesCount += 1
        testSuitename = child.attrib['name']
        totalTests = int(child.attrib['tests'])
        failed = int(child.attrib['failures'])
        disabled = int(child.attrib['disabled'])
        testSuiteBeginTime = child.attrib['timestamp']
        tempTest = []
        successTest = []
        for test in child:
            testName = test.attrib['name']
            testTime = process_time(float(test.attrib['time']))
            sortKey  = int(test.attrib['time'])
            testBeginTime = test.attrib['timestamp']
            testStatus = test.attrib['status'].upper()
            testResult = test.attrib['result'].upper()
            testClassname = test.attrib['classname']
            # Getting all of the failure messages
            testFailures = []
            for failure in test:
                testFailure = failure.attrib['message']
                testFailures.append({
                    'failure': testFailure
                })

            # If there are no failures dont add it to the JSON
            if testFailures:
                failedSuit = {
                    'name': testName,
                    'time': testTime,
                    'sortKey':sortKey,
                    'begintime':testBeginTime,
                    'status': testStatus,
                    'message': testFailures,
                    'classname':testClassname,
                    'isFailed':True
                }
                tempTest.append(failedSuit)
                data['failedsuites'].append(failedSuit)
                totalTests-=1
            else:
                successSuit = {
                    'name': testName,
                    'sortKey':sortKey,
                    'status': testStatus,
                    'time': testTime,
                    'begintime':testBeginTime,
                    'message': testResult,
                    'classname':testClassname
                }
                tempTest.append(successSuit)
                successTest.append(successSuit)

        print(classesCount)
        tempTest.sort(key = lambda x:x["sortKey"],reverse=True)
        successTest.sort(key = lambda x:x["sortKey"],reverse=True)
        print(tempTest)
        allTempTestCase.extend(tempTest)
        tempTestSuite = {
            'name': testSuitename,
            'tests': totalTests,
            'failures': failed,
            'disabled': disabled,
            'testsuite': successTest,
            'begintime':testSuiteBeginTime,
        }
        data['testsuites'].append(tempTestSuite)
    allTempTestCase.sort(key = lambda x:x["sortKey"],reverse=True)
    try:
        if os.name != 'nt':
            data['classes'] = classesCount
            data['slowestCount'] = 20
            data['slowestsuites'] = allTempTestCase[:20]
            data['cpu'] = readPicData('cpu.png')
            data['mem'] = readPicData('mem.png')
            data['disk'] = readPicData('disk.png')
            data['thread'] = readPicData('thread.png')
            data['rw_count'] = readPicData('rw_count.png')
        else:
            data['classes'] = classesCount
            data['slowestCount'] = 20
            data['slowestsuites'] = allTempTestCase[:20]
            data['cpu'] = readPicData('cpu.png')
            data['mem'] = readPicData('mem.png')
            data['disk'] = readPicData('disk.png')
            data['thread'] = readPicData('thread.png')
            data['rw_count'] = readPicData('rw_count.png')
            data['num_handles'] = readPicData('num_handles.png')
    except:
        print ('process exception') 
        return data
    else:
        return data
def create_html(data):
    """ Turns the JSON object into a HTML file.
        Will grab the template and render it with our JSON object.
    """
    templateLoader = FileSystemLoader(searchpath="./")
    templateEnv = Environment(loader=templateLoader)
    template = templateEnv.get_template(TEMPLATE_FILE)

    with open(OUTPUT_FILE, "w") as output_html:
        output_html.write(template.render(test_overview=data, test_suites=data['testsuites']))
    shutil.move(OUTPUT_FILE,"./TestResult")

if __name__ == "__main__":
    OUTPUT_FILE = sys.argv[2]+"_"+datetime.datetime.now().strftime('%Y-%m-%d_%H-%M-%S')+".html"
    json_data = process_input(sys.argv[1])
    create_html(json_data)
