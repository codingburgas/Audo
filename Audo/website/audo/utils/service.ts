export const updateTotalStorageTests = () => {

    let currentTest: any = window.location.href.split('/').pop();
    let testIsNotFinished = !localStorage.getItem('testsName') ? true:  localStorage.getItem('testsName')?.indexOf(currentTest) === -1;
    if(!localStorage.getItem('testsName') || testIsNotFinished) {
        if(localStorage.getItem('totalTests')) {
            let totalStorageTests = localStorage.getItem('totalTests');
            let str = localStorage.getItem('testsName') + currentTest;
            let newTestName = !localStorage.getItem('testsName') ? currentTest : str;
            localStorage.setItem('testsName', newTestName);
            if(totalStorageTests) {
                let intTotal = parseInt(totalStorageTests);
                let total: any = intTotal + 1;
                total = total.toString();
                localStorage.setItem('totalTests', total);
            }
    
        }
        else {
            localStorage.setItem('totalTests', '1');
            localStorage.setItem('testsName', currentTest);
        }

    }
};