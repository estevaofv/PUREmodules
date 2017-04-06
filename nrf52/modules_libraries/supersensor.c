#include "supersensor.h"

#define NRF_LOG_MODULE_NAME "APP"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_drv_twi.h"
#include "bsp.h"

#include "i2c_driver.h"
#include "lis3mdl.h"
#include "lis2de.h"
#include "vl53l0.h"
#include "si1153.h"
#include "veml6075.h"
#include "bme280.h"




ss_response test_SuperSensor_init(nrf_drv_twi_t twi_master){
    //uint8_t magnet_ID = 
    lis3mdl_init(twi_master);
    //uint8_t accel_ID = 
    lis2de_init(twi_master);
    //uint8_t uva_ID = 
    veml6075_init(twi_master);
    //uint8_t prox_ID = 
    si1153_init(twi_master);
    //uint8_t bme280_id = 
    bme280_init(twi_master); 


    return SS_SUCCESSFUL;

}

bool test_individual_sensors(nrf_drv_twi_t twi_master){
        
    test_SuperSensor_init(twi_master);

    if(!lis3mdl_pass(twi_master)){
        return false;
    }

    if(!lis2de_pass(twi_master)){
        return false;
    }

    if(!veml6075_pass(twi_master)){
        return false;
    }

    if(!si1153_pass(twi_master)){
        return false;
    }

    if(!bme280_pass(twi_master)){
        return false;
    } 


    return true;

}

void test_SuperSensor(nrf_drv_twi_t twi_master){

    bool supersensor_pass = test_individual_sensors(twi_master);

    if(supersensor_pass){
        bsp_board_led_on(0);
    }
}



ss_response test_SuperSensor_run(nrf_drv_twi_t twi_master){
    //uint8_t magnet_ID = 
    run_lis3mdl(twi_master);
    //uint8_t accel_ID = 
    run_lis2de(twi_master);
    //uint8_t uva_ID = 
    run_veml6075(twi_master);
    //uint8_t prox_ID = 
    run_si1153(twi_master);
    //uint8_t bme_ID = 
    run_bme280(twi_master); 

    return SS_SUCCESSFUL;

}