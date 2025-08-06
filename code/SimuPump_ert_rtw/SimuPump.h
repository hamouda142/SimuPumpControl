/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SimuPump.h
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

#ifndef SimuPump_h_
#define SimuPump_h_
#ifndef SimuPump_COMMON_INCLUDES_
#define SimuPump_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif                                 /* SimuPump_COMMON_INCLUDES_ */

#include "SimuPump_types.h"
#include <math.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T pressure;                     /* '<S5>/fromWS_Signal 1' */
} B_SimuPump_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK;              /* '<S5>/fromWS_Signal 1' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK_f;            /* '<S4>/fromWS_Signal 1' */

  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK;              /* '<S5>/fromWS_Signal 1' */

  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK_p;            /* '<S4>/fromWS_Signal 1' */

  uint8_T is_active_c3_SimuPump;       /* '<S1>/ Stateflow Chart' */
  uint8_T is_c3_SimuPump;              /* '<S1>/ Stateflow Chart' */
} DW_SimuPump_T;

/* Real-time Model Data Structure */
struct tag_RTM_SimuPump_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint16_T clockTick0;
    time_T stepSize0;
    uint16_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_SimuPump_T SimuPump_B;

/* Block states (default storage) */
extern DW_SimuPump_T SimuPump_DW;

/* Model entry point functions */
extern void SimuPump_initialize(void);
extern void SimuPump_step(void);
extern void SimuPump_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SimuPump_T *const SimuPump_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S2>/Switch' : Unused code path elimination
 * Block '<S2>/pump OFF' : Unused code path elimination
 * Block '<S2>/pump ON' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SimuPump'
 * '<S1>'   : 'SimuPump/Control Logic'
 * '<S2>'   : 'SimuPump/Motor Control'
 * '<S3>'   : 'SimuPump/Sensor Simulation'
 * '<S4>'   : 'SimuPump/Signal Editor'
 * '<S5>'   : 'SimuPump/Signal Editor1'
 * '<S6>'   : 'SimuPump/Control Logic/ Stateflow Chart'
 */
#endif                                 /* SimuPump_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
