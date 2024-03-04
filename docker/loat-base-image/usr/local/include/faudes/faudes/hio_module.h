/** @file hio_module.h Class describing the I/O based hierarchy */

/* Hierarchical IO Systems Plug-In for FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2006  Sebastian Perk 
   Copyright (C) 2006  Thomas Moor 
   Copyright (C) 2006  Klaus Schmidt

*/

#ifndef FAUDES_HIO_MODULE_H
#define FAUDES_HIO_MODULE_H

#include "hio_functions.h"
#include <list>
#include <cmath> 

namespace faudes {

/**
* Recurring structure in hierarchies designed according to the I/O based DES framework.
* The HioModule class is a composite pattern providing access to the components of  a 
* I/O-controller synthesis problem for a composite I/O-plant:
* 
* - Operator-constraint: describes liveness properties of I/O-plant, together with
* 			       environment-constraint
* - Plant: abstraction and at the same time specification  of the external
* 		closed-loop behaviour of the HioModule.
* - Controller enforcing the desired behaviour
* - children-vector of (pointers to) subordinate HioModules
* - Environment
* - Environment-constraint: describes liveness properties of I/O-plant, together with
* 				  operator-constraint
* 
* The plants of the subordinate HioModules and the environment form the
* uncontrolled behaviour of the HioModule.
* 
*  @ingroup hiosysplugin 
*/

class HioModule {
       
  public:
    
    /**
     * constructor
     */
     HioModule(void);


    /**
     * copy constructor
     */
     HioModule(const HioModule& rOtherHioModule);

    /**
     * virtual destructor
     */
     virtual ~HioModule(void) {};
     
    /**
     * Clear all members of the HioModule
     */
     void Clear();
     
     
    /**
     * Set name of HioModule
     *
     * @param rName
     *  Name to set
     */
     void Name(const std::string& rName);
	 
    /**
     * Return name of HioModule
     *
   * @return
   *   Name of HioModule
     */
     std::string Name() const;
     
    /**
     * Set index of HioModule. 
     *
     * @param Index
     *   Index to set  
     */
     void Index(const Idx Index);
     
    /**
     * Return index of HioModule. 
     *
     * @return
     *   Index of HioModule
     */
	Idx Index() const;
     
    /**
     * Set Operator-Constraint of HioModule
     *
     * @param rOpConstr
     *   Operator-Constraint to set
     */
     void OpConstr(const HioConstraint& rOpConstr);
	 
     /** 
     * Return Operator-Constraint of HioModule
     *
     * @return
     *   Operator-Constraint of HioModule
     */
     HioConstraint OpConstr() const;
     
    /**
     * Set HioPlant of HioModule
     *
     * @param rHioPlant
     *   HioPlant to set
     */
     void Plant(const HioPlant& rHioPlant);
	 
     /** 
     * Return HioPlant of HioModule
     *
     * @return
     *   HioPlant of HioModule
     */
     HioPlant Plant() const;
     
    /**
     * Set HioController of HioModule
     *
     * @param rHioController
     *   HioController to set
     */
     void Controller(const HioController& rHioController);
	 
     /** 
     * Return HioController of HioModule
     *
     * @return
     *   HioController of HioModule
     */
     HioController Controller() const;
     
    /** 
     * Return Children of HioModule
     *
     * @return
     *   Children of the HioModule
     */ 
     std::vector<HioModule*> Children() const;
	 
    /**
     * Set Children of HioModule
     *
     * @param rChildren
     *   vector of children to set
     */
	 void Children(const std::vector<HioModule*>& rChildren);

	 /**
     * Set HioEnvironment of HioModule
     *
     * @param rHioEnvironment
     *   HioEnvironment to set
     */
     void Environment(const HioEnvironment& rHioEnvironment);
	 
     /** 
     * Return HioEnvironment of HioModule
     *
     * @return
     *   HioEnvironment of HioModule
     */
     HioEnvironment Environment() const;
     
    /**
     * Set Environment-Constraint of HioModule
     *
     * @param rEnvConstr
     *   Environment-Constraint to set
     */
     void EnvConstr(const HioConstraint& rEnvConstr);
	 
     /** 
     * Return Environment-Constraint of HioModule
     *
     * @return
     *   Environment-Constraint of HioModule
     */
     HioConstraint EnvConstr() const;
     
    /**
     * Insert HioModule to list of children
     *
     * @param rChild
     *   Child HioModule to insert to list of children
     */  
     void InsChild(HioModule* rChild);
	 
//////////////////////////////////////////////////////////////////////////
// from here to 'private': M.Musunoi - design specific functions
     
//### M.Musunoi ###
	 /**
     * This is a function to set the x and y position of the HioModule.
     *
     * @param Xpos
     *   Position at the X-Axis of an x0y-System  
     * @param Ypos
     *   Position at the Y-Axis of an x0y-System
     */
     void Position(const int Xpos, const int Ypos);
//### M.Musunoi ###

//### M.Musunoi ###	 
    /**
     * This is a function to set the type of the HioModule; by type we mean an array
     * of length 5 where each position has a specific semnification:
     *
     *     *************** Interpretation of mType[] *******
     *     ************* Capacity:        mType[0] *********
     *     ************* Take from left:  mType[1] *********
     *     ************* Take from right: mType[2] *********
     *     ************* Deliver to left: mType[3] *********
     *     ************* Deliver to left: mType[4] *********
     *     *************************************************
     *
     * @param type
     *   type of the HioModule
     */  
     void TypeHioModule(int type[5]);
//### M.Musunoi ###
     
          
    /**
      * This function reads the model from the given library and
      * sets the following private variables of the HioModule. 
      * The library must contain the following files:
      *      
      *      plantCBx.gen - IO-Plant model of the simulated work unit (to set mIOPlant);
      *      constrP_CBx.gen - Operator constraints of the IO Plant model (if the
      *                        model doesn't require any operator constraints at
      *                        least an empty generator must be available) (mLcConstr)
      *      constrE_CBx.gen - Environment constraints of the IO Plant model (at
      *                        least an empty generator must be available) (mLeConstr)
      *            
      *    for GUI purpose: 
      *      symbolic picture of the work unit in *.png format
      *
      * The file names must be given as described above, and the events respect the 
      * following format:
      *            "CBx_..." (e.g.: CBx_rdy, CBx_full, CBx_stby,...)  
      *      
      * @param path
      *   string path indicating to the folder of the library to load; 
      *   (required format: ../CBx/)
      *
      * todo: for GUI load image
      */
     void ReadHioPlant(const std::string path);
     
     
    /**
      * This function reads the model describing the interaction of IO-Plants with 
      * the environment and sets the private variable mIOEnvironment. As a next 
      * logical step this generator must be adapted to the IO-Plants that interact
      * with each other.
      *
      * @param path
      *   string path indicating to the folder of the library to load;
      */
    void ReadHioEnv(const std::string path);
    
    
/**
  * This function converts a generator by renaming all events from 
  * "CBx_..." to "CBi_...";
  * 
  * all properties of the input generator are inherited by the output generator;
  * as a standard all events used in this plugin have the following name format:
  *  "CBx_..."
  *
  * @param rOldGen
  *   generator to convert
  * @param i
  *   new parameter to replace x 
  * @param rResGen
  *   Reference to the resulting converted generator (result)
  */
void AdjusTimedGenerator(
                     const Generator& rOldGen, 
                     const int i,
                     Generator& rResGen);

     
/**
  * AdjustHioPlant(): convenience function (derived from AdjusTimedGenerator())to
  * allow also the conversion of HioPlants
  *
  * @param rOldHioPlant
  *   HioPlant to convert
  * @param i
  *   new parameter to replace x 
  * @param rResult
  *   Reference to the resulting converted HioPlant (result)
  */
void AdjustHioPlant(
                    const HioPlant& rOldHioPlant,
                    const int i,
                    HioPlant& rResult);


/**
  * This function converts an alphabet by renaming all events from 
  * "CBx_..." to "CBi_...";
  * as a standard all events used in this plugin have the following name format:
  *  "CBx_...";
  * Warning: This function does not preserves the attributes of the events!
  *
  * @param rOldAlph
  *   Alphabet to convert
  * @param i
  *   new parameter to replace x 
  * 
  * @param rResAlph
  *   Reference to the resulting converted alphabet (result)
  */
void AdjustAlphabet(
                     const EventSet& rOldAlph, 
                     const int i,
                     EventSet& rResAlph);


/**
  * AdjustEnvironment(): In order to describe the interaction between two IO-Plants
  * we use the IO-Environment. This function adjusts the master copy 
  * (IOEnvironmentX) to the two IO-Plants. The position of the plants to each
  * other must be set.
  * 
  * @param rHioEnvX
  *   the master copy generator of the environment model
  * @param rHioModule1
  *   first HioModule 
  * @param rHioModule2
  *   second HioModule
  * @param rResEnv
  *   Reference to the resulting environment.
  */
void AdjustHioEnvironment(
                       const HioEnvironment& rHioEnvX,
                       const HioModule* rHioModule1,
                       const HioModule* rHioModule2,
                       HioEnvironment& rResEnv);


/**
  * AdjustHioController: convenience function derived from AdjustHioEnvironment() in 
  * order to adjust an IOController to any two IO-Plants which must enforce a 
  * well-defined specification
  *
  * @param rHioController
  *   the input controller to convert 
  * @param HioModule1
  *   pointer to first HioModule
  * @param HioModule2
  *  pointer to second HioModule
  * @param rResCont
  *  Reference to resulting controller
  */
void AdjustHioController(
                      const HioController& rHioController,
                      const HioModule* HioModule1,
                      const HioModule* HioModule2,
                      HioController& rResCont);


/**
  * this function renames all relevant member of the HioModule. These are:
  *       mHioPlant, mLcConstr, mLeConstr, mHioEnvironment, mHioController, mName
  *
  * @param i
  *   the new Id of the HioModule
  */
void RenameHioModule(const int i);
  
  
   /**
     * chooseSpec: this function searches through an appropriate folder (based on
     * the maximal capacity resulting from the ChildList) for available
     * specifications and allows the user to choose one of the found specifications;
     * After the user has chosen a specification, this function sets the IO-Plant,
     * the constraints and the alphabets of the actual HioModule.
     * The path must have the following format: "../Spec/"
     *
     * Warning: The computation of the IO-Controller is not triggered by this function,
     * it must be started separately!
     *
     * @param path
     *   Path to the folder containing the specifications
     * @return
     *   list of strings with available specifications
     */
std::vector<std::string> ChooseSpec(
                                    const std::string path); 
   
   /**
     * Compute: this function prepares the data required for HioSynth() function.
     * If all data is available, HioSynth() is called and the resulting generator
     * is the IOController for the given specification. 
     */
     void Compute();
     
     
   /**
     * FindController(): this function searches in the folder of a chosen 
     * specification for an already computed IO-controller which enforces this
     * specification.
     * Furthermore must the IO-controller only be adjusted to the IO-Modules that
     * we need to control. (to adjust call adjustController())
     * @return
     *   true if a IO-Controller is available 
     */
     bool FindController();
     
     
   /**
     * Save: this function saves the computed controller in the same folder with 
     * the specification that this controller enforces 
     */
     void SaveController();

     
   /**
     * MyPath(): based on the type of the HioModule, this is a convenience
     * function to establish the local path where to Write/Read from. (This function
     * is used up to now only by FindController() and SaveController())
     *
     * @return
     *   string: path to the actual IO-Module  
     */
     std::string MyPath();
     
     /**********************************************
     **********************************************
     *
     * functions to call properties of the HioModule
     **********************************************
     ***********************************************/
     
    /** 
     * function to call the x-Position of the HioModule
     *
     * @return
     *   x-Position of the HioModule
     */
     int Xpos() const;

    /** 
     * function to call the y-Position of the HioModule
     *
     * @return
     *   y-Position of the HioModule
     */
     int Ypos() const;
     
    /** 
     * function to call the Type of the HioModule
     *
     * @return
     *   array of length 5 describing the type of the HioModule
     */ 
     int* TypeHioModule() const;
     
    /**
     * function to encode to Type of the HioModule (function has only an 
     * informational character). 
     *
     *     *************** Interpretation of mType[] *******
     *     ************* Capacity:        mType[0] *********
     *     ************* Take from left:  mType[1] *********
     *     ************* Take from right: mType[2] *********
     *     ************* Deliver to left: mType[3] *********
     *     ************* Deliver to left: mType[4] *********
     *     *************************************************
     *
     * @param type
     *   the type to be encoded
     */
     void EncodeType(const std::string type);

  private:
  
     //Name
     std::string mName;
     
     //Identity
     Idx mIndex;
     
     // Operator-Constraint
     HioConstraint mOpConstr;
     
     // I/O-Plant
     HioPlant mPlant;
	 
     // IO-Controller 
     HioController mController;
     
     // Children
     std::vector<HioModule*> mChildren;
	 
     // IO-Environment 
     HioEnvironment mEnvironment;
     
     // Environment-Constraint
     HioConstraint mEnvConstr;
     
	/////////////////////////////////////////////////////////////////////
	// from here to end of file: design specific functions by M.Musunoi
	// will be outsourced to something like hiodesign.h
	 
     // operational mode of the HioModule
     int mType[5];
     
     // define the position in a x0y coordinate system; mXpos = 0 and mYpos =0 is 
     // reserved for the general IOModule CBx
     int mXpos;
     int mYpos;
     
      }; // end of HioModule class definition

/*******************************************************************************
 ***************************END OF IOMODULE CLASS DEFINITION********************
 ******************************************************************************/
 
/**
  * GroupHioModules: This function groups two or more HioModules to a new HioModule. The new 
  * HioModule represents the uncontrolled behaviour of the composed HioModules.
  *
  * @param rChildren
  *   vector of HioModules to group
  * @param rParentModule
  *   resulting HioModule
  */
void GroupHioModules(
                    const std::vector<HioModule*>& rChildren,
                    HioModule& rParentModule);

/**
 * This function creates new specification given by the type ("xxxxx")
 * Note: The core of this function is a template specification model (SpecCB12.gen).
 * Based on this model are the specifications created, by simply adding corresponding
 * states and transitions. Hence, for different models, this function can not be
 * used directly, but can serve as an example.
 *
 * @param mType
 *   By the type we specify the desired behaviour we want to model
 * @param rHioSpec
 *   HioPlant reference to the resulting specification (result)
 * @param constrP
 *   Generator to the resulting operator constraint for the specification
 * @param constrE
 *   Generator to the resulting environment constraint for the specification
 */
void CreateSpec(int mType[5], HioPlant& rHioSpec, Generator& constrP, Generator& constrE);

/** This function creates constraints which describe the condition of completeness
 * and Yp-liveness of a Specification. The implementation follows the same algorithm
 * as the CreateSpec() function, and has the same limitation: it is only for use 
 * with a specific model
 *
 * @param mType
 *   By the type we specify type of the specification to build constraint for
 * @param constrP
 *   Generator to the resulting operator constraint for the specification
 * @param constrE
 *   Generator to the resulting environment constraint for the specification
 */
void CreateConstraint(int mType[5], Generator& constrP, Generator& constrE);

               
} // end namespace faudes  

#endif    
