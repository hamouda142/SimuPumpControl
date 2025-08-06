/*
 * File: SimuPump.c
 *
 * Code generated for Simulink model 'SimuPump'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Wed Aug  6 04:33:46 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SimuPump.h"
#include "rtwtypes.h"
#include "SimuPump_private.h"

/* Named constants for Chart: '<S1>/ Stateflow Chart' */
#define SimuPump_IN_Emergency          ((uint8_T)1U)
#define SimuPump_IN_Flush              ((uint8_T)2U)
#define SimuPump_IN_Idle               ((uint8_T)3U)
#define SimuPump_IN_Suction            ((uint8_T)4U)

/* Block signals (default storage) */
B_SimuPump_T SimuPump_B;

/* Block states (default storage) */
DW_SimuPump_T SimuPump_DW;

/* Real-time model */
static RT_MODEL_SimuPump_T SimuPump_M_;
RT_MODEL_SimuPump_T *const SimuPump_M = &SimuPump_M_;

/* Model step function */
void SimuPump_step(void)
{
  /* local block i/o variables */
  real_T rtb_mode;

  /* FromWorkspace: '<S5>/fromWS_Signal 1' */
  {
    real_T *pDataValues = (real_T *) SimuPump_DW.fromWS_Signal1_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) SimuPump_DW.fromWS_Signal1_PWORK.TimePtr;
    int_T currTimeIndex = SimuPump_DW.fromWS_Signal1_IWORK.PrevIndex;
    real_T t = SimuPump_M->Timing.t[0];
    if (t > pTimeValues[7]) {
      SimuPump_B.pressure = 0.0;
    } else {
      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[7]) {
        currTimeIndex = 6;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      SimuPump_DW.fromWS_Signal1_IWORK.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            SimuPump_B.pressure = pDataValues[currTimeIndex];
          } else {
            SimuPump_B.pressure = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex = currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          SimuPump_B.pressure = (real_T) rtInterpolate(d1, d2, f1, f2);
          pDataValues += 8;
        }
      }
    }
  }

  /* FromWorkspace: '<S4>/fromWS_Signal 1' */
  {
    real_T *pDataValues = (real_T *) SimuPump_DW.fromWS_Signal1_PWORK_f.DataPtr;
    real_T *pTimeValues = (real_T *) SimuPump_DW.fromWS_Signal1_PWORK_f.TimePtr;
    int_T currTimeIndex = SimuPump_DW.fromWS_Signal1_IWORK_p.PrevIndex;
    real_T t = ((SimuPump_M->Timing.clockTick1) * 50.0);
    if (t > pTimeValues[7]) {
      rtb_mode = 0.0;
    } else {
      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[7]) {
        currTimeIndex = 6;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      SimuPump_DW.fromWS_Signal1_IWORK_p.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            rtb_mode = pDataValues[currTimeIndex];
          } else {
            rtb_mode = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex = currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          rtb_mode = (real_T) rtInterpolate(d1, d2, f1, f2);
          pDataValues += 8;
        }
      }
    }
  }

  /* Chart: '<S1>/ Stateflow Chart' */
  if (SimuPump_DW.is_active_c3_SimuPump == 0) {
    SimuPump_DW.is_active_c3_SimuPump = 1U;
    SimuPump_DW.is_c3_SimuPump = SimuPump_IN_Idle;
  } else {
    switch (SimuPump_DW.is_c3_SimuPump) {
     case SimuPump_IN_Emergency:
      if (((rtb_mode == 0.0) && (SimuPump_B.pressure >= 0.2)) ||
          (SimuPump_B.pressure <= 0.8)) {
        SimuPump_DW.is_c3_SimuPump = SimuPump_IN_Idle;
      }
      break;

     case SimuPump_IN_Flush:
      if ((SimuPump_B.pressure < 0.2) || (SimuPump_B.pressure > 0.8)) {
        SimuPump_DW.is_c3_SimuPump = SimuPump_IN_Emergency;
      } else if (((rtb_mode == 1.0) && (SimuPump_B.pressure >= 0.2)) ||
                 (SimuPump_B.pressure <= 0.8)) {
        SimuPump_DW.is_c3_SimuPump = SimuPump_IN_Suction;
      }
      break;

     case SimuPump_IN_Idle:
      if (((rtb_mode == 1.0) && (SimuPump_B.pressure >= 0.2)) ||
          (SimuPump_B.pressure <= 0.8)) {
        SimuPump_DW.is_c3_SimuPump = SimuPump_IN_Suction;
      }
      break;

     default:
      /* case IN_Suction: */
      if (((rtb_mode == 2.0) && (SimuPump_B.pressure >= 0.2)) ||
          (SimuPump_B.pressure <= 0.8)) {
        SimuPump_DW.is_c3_SimuPump = SimuPump_IN_Flush;
      } else if (SimuPump_B.pressure > 0.8) {
        SimuPump_DW.is_c3_SimuPump = SimuPump_IN_Emergency;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/ Stateflow Chart' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  SimuPump_M->Timing.t[0] =
    ((time_T)(++SimuPump_M->Timing.clockTick0)) * SimuPump_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [50.0s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 50.0, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    SimuPump_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void SimuPump_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SimuPump_M->solverInfo,
                          &SimuPump_M->Timing.simTimeStep);
    rtsiSetTPtr(&SimuPump_M->solverInfo, &rtmGetTPtr(SimuPump_M));
    rtsiSetStepSizePtr(&SimuPump_M->solverInfo, &SimuPump_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&SimuPump_M->solverInfo, (&rtmGetErrorStatus
      (SimuPump_M)));
    rtsiSetRTModelPtr(&SimuPump_M->solverInfo, SimuPump_M);
  }

  rtsiSetSimTimeStep(&SimuPump_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&SimuPump_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&SimuPump_M->solverInfo, false);
  rtsiSetSolverName(&SimuPump_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(SimuPump_M, &SimuPump_M->Timing.tArray[0]);
  SimuPump_M->Timing.stepSize0 = 50.0;

  /* Start for FromWorkspace: '<S5>/fromWS_Signal 1' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0 } ;

    static real_T pDataValues0[] = { 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1.0, 0.5 } ;

    SimuPump_DW.fromWS_Signal1_PWORK.TimePtr = (void *) pTimeValues0;
    SimuPump_DW.fromWS_Signal1_PWORK.DataPtr = (void *) pDataValues0;
    SimuPump_DW.fromWS_Signal1_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<S4>/fromWS_Signal 1' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0 } ;

    static real_T pDataValues0[] = { 0.0, 1.0, 2.0, 0.0, 1.0, 2.0, 3.0, 0.0 } ;

    SimuPump_DW.fromWS_Signal1_PWORK_f.TimePtr = (void *) pTimeValues0;
    SimuPump_DW.fromWS_Signal1_PWORK_f.DataPtr = (void *) pDataValues0;
    SimuPump_DW.fromWS_Signal1_IWORK_p.PrevIndex = 0;
  }
}

/* Model terminate function */
void SimuPump_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
