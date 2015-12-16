function handle1(cnt){
    gui.debug("1 = "+cnt);
    console.info("1 == "+cnt);
}
gui.testSignal.connect(handle1);

function handle2(cnt){
    console.info("2 == "+cnt);
    gui.debug("2 == "+cnt);
}
gui.testSignal.connect(handle2);
