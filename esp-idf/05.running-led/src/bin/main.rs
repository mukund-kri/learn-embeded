#![no_std]
#![no_main]

use esp_backtrace as _;
use esp_hal::{
    delay::Delay,
    clock::CpuClock,
    gpio::{Level, Output},
    main,
};



#[main]
fn main() -> ! {
    // generator version: 0.2.2

    let config = esp_hal::Config::default().with_cpu_clock(CpuClock::max());
    let peripherals = esp_hal::init(config);

    let mut leds = [
        Output::new(peripherals.GPIO19, Level::Low),
        Output::new(peripherals.GPIO21, Level::Low),
        Output::new(peripherals.GPIO22, Level::Low),
        Output::new(peripherals.GPIO23, Level::Low),
    ];

    esp_println::logger::init_logger_from_env();

    let delay = Delay::new();
    loop {
        for led in leds.iter_mut() {
            led.toggle();
            delay.delay_millis(1000);
            led.toggle();
        }
    }
}
