/** @file iop_simplenet.h Simple networked events via TCP/IP */

/* 
   FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2008, Thomas Moor
   Exclusive copyright is granted to Klaus Schmidt

*/



#ifndef FAUDES_IOP_SIMPLENET_H
#define FAUDES_IOP_SIMPLENET_H

#include "corefaudes.h"
#include "iop_vdevice.h"

 
namespace faudes {


/**
 * Simplenet node address.
 *
 * A node address consists of an IP address and a TCP port.
 * This convenience class implements string based access to both components.
 *
 */

class FAUDES_API SimplenetAddress {

public:

  /** Default constructor */
  SimplenetAddress(void);

  /** Copy construct */
  SimplenetAddress(const SimplenetAddress& rOther);

  /** Construct from string */
  SimplenetAddress(const std::string& rString);

  /** Return true if valid */
  bool Valid(void) const;

  /** Get IP address */
  std::string Ip(void) const { return mIp; };

  /** Get TCP port */
  int Port(void) const { return mPort; };

  /** Get as colon seperated string */
  std::string IpColonPort(void) const;

  /** Set IP address */
  void Ip(std::string ip) { mIp=ip; };

  /** Set TCP port  */
  void Port(int port) { mPort=port; };

  /** Set from colon seperated string */
  void IpColonPort(std::string ipcolonport);
  
  /** Order for sorting containers of addresses */
  bool operator < (const SimplenetAddress& rOther) const;

 protected:

  /** Ip address */  
  std::string mIp;

  /** TCP port */
  int mPort;

};



// only compile for simplenet support
#ifdef FAUDES_IODEVICE_SIMPLENET




/**
 * Configuration of a network output mapping.
 *
 * There is nothing to configure here: any client that
 * connects to this device can subscribe to any output event.
 * Future versions of libFAUDES may specify a set of receipent
 * clients.
 *
 */

class FAUDES_API AttributeSimplenetOutput : public AttributeVoid {

FAUDES_TYPE_DECLARATION(Void,AttributeSimplenetOutput,AttributeVoid)

public:

  /** Default constructor */
  AttributeSimplenetOutput(void) : AttributeVoid() {}; 

  /** Test for default value (always, since we have no data) */
  virtual bool IsDefault(void) const {return true;};

  /** Clear to default */
  virtual void Clear(void) {};

protected:

  /** Copy method 
   *
   * @param rSrcAttr
   *   Source to copy from
   * @return
   *   Ref to this attribute
   */
  void DoAssign(const AttributeSimplenetOutput& rSrcAttr) 
  {(void) rSrcAttr;};

  /**
   * Reads the attribute from TokenReader, see AttributeVoid for public wrappers.
   * 
   * If the current token indicates a input mapping, the method reads that
   * section. Else it does nothing. Exceptions may only be thrown
   * on invalid data within the section. The label argument is ignored, we use the 
   * hardcoded section "Output" for output attributes. The context argument is ignored.
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information
   *
   * @exception Exception
   *   - IO error (id 1)
   */
  virtual void DoRead(TokenReader& rTr,const std::string& rLabel="", const Type* pContext=0);
 
  /**
   * Writes the attribute to TokenWriter, see AttributeVoid for public wrappers.
   *
   * Writes the output mapping data. The label argument is ignored, we use 
   * the hardcoded section "Output". The context argument is ignored.  
   *
   * @param rTw
   *   TokenWriter to write to
   * @param rLabel
   *   Section to write
   * @param pContext
   *   Read context to provide contextual information
   *
   * @exception Exception
   *   - IO error (id 2)
   */
  virtual void DoWrite(TokenWriter& rTw,const std::string& rLabel="", const Type* pContext=0) const;

}; // end class AttributeSimplenetOutput


/**
 * Configuration of a network input mapping.
 *
 * There is nothing to configure here: any server that
 * provides the repective event will be accepted. Future versions 
 * of libFAUDES may specify a set of servers here.
 *
 */

class FAUDES_API AttributeSimplenetInput : public AttributeVoid {

FAUDES_TYPE_DECLARATION(Void,AttributeSimplenetInput,AttributeVoid)

public:

  /** Default constructor (no triggers) */
 AttributeSimplenetInput(void) : AttributeVoid() {}; 

  /** Test for default value (always, since we have no data) */
  virtual bool IsDefault(void) const {return true;};

  /** Clear to default */
  virtual void Clear(void) {};

protected:

  /** Copy method 
   *
   * @param rSrcAttr
   *   Source to copy from
   * @return
   *   Ref to this attribute
   */
  void DoAssign(const AttributeSimplenetInput& rSrcAttr) 
  {(void) rSrcAttr;};


  /**
   * Reads the attribute from TokenReader, see AttributeVoid for public wrappers.
   * 
   * If the current token indicates a input mapping, the method reads that
   * section. Else it does nothing. Exceptions may only be thrown
   * on invalid data within the section. The label argument is ignored, we the hardcoded
   * section "Input" for input device attributes. The context argument is ignored.
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information
   *
   * @exception Exception
   *   - IO error (id 1)
   */
  virtual void DoRead(TokenReader& rTr,const std::string& rLabel="", const Type* pContext=0);
 
  /**
   * Writes the attribute to TokenWriter, see AttributeVoid for public wrappers.
   *
   * Writes the input mapping data.The label argument is ignored, we use 
   * the hardcoded section "Input". The context argument is ignored.  
   *
   * @param rTw
   *   TokenWriter to write to
   * @param rLabel
   *   Section to write
   * @param pContext
   *   Read context to provide contextual information
   *
   * @exception Exception
   *   - IO error (id 2)
   */
  virtual void DoWrite(TokenWriter& rTw,const std::string& rLabel="", const Type* pContext=0) const;

}; // end class AttributeSimplenetInput



/**
 * Configuration of a networked input or output 
 *
 * This class is derived from the AttributeDeviceEvent to specialise
 * for networked input and output mapping.
 *
 */

class FAUDES_API AttributeSimplenetEvent : public AttributeDeviceEvent {

FAUDES_TYPE_DECLARATION(Void,AttributeSimplenetEvent,AttributeDeviceEvent)

public:

  /** Default constructor (no mapping at all) */
  AttributeSimplenetEvent(void);

  /** Copy constructor */
  AttributeSimplenetEvent(const AttributeSimplenetEvent& rOtherAttr);

  /** Test for default value (never) */
  virtual bool IsDefault(void) const {return false;};

  /** Clear */
  virtual void Clear(void)  { AttributeDeviceEvent::Clear(); };

  /**  Get output mapping */
  const AttributeSimplenetOutput*  Outputp(void) const {
    return static_cast<AttributeSimplenetOutput*>(mpOutputAttribute); };

  /**  Get input mapping */
  const AttributeSimplenetInput*  Inputp(void) const {
    return static_cast<AttributeSimplenetInput*>(mpInputAttribute); };

protected:

  /** DoAssign */
  void DoAssign(const AttributeSimplenetEvent& rSrc)  
  { AttributeDeviceEvent::DoAssign(rSrc);};

  /** Prototype, input (construct on first use static) */
  static const AttributeSimplenetInput* InputPrototypep(void);

  /** Prototype, output (construct on first use static) */
  static const AttributeSimplenetOutput* OutputPrototypep(void);

}; // class AttributeSimplenetEvent


/**
 * An nDevice implements networked IO via a simple TCP/IP protocol. 
 *
 * @section SecIodeviceNDev1 Networking
 *
 * The purpose of this implementation of networked discrete events is to provide
 * a basis for case studies. However, simple networked events via nDevice must not 
 * be confused with ongoing research that addresses synchronisation and real 
 * time behaviour. We take a really pragmatic approach here.
 *
 * Our <em>network</em> is identified by its <em>network name</em>. It consists
 * a number of <em>nodes</em>, each identified by its <em>node name</em>. In the current implementation,
 * each node knows about the entire network ie knows about all other nodes. Each node plays two roles:
 * - the <em>server</em> role to send event notifications, and
 * - the <em>client</em> role to receive event notifications.
 *
 * In their server role, each node is configured to listen on its <em>server port</em> for incomming 
 * TCP connections. When a client (i.e. some other node in client role) connects to the TCP port, the server 
 * replies to a simple command set in order to allow the client to subscribe to the nodes output events.
 * When the application executes an output event on the node, this is notified to all connected clients and
 * the clients will interpret the event as an input reading. Vice versa, the each node itself has the 
 * role of a client and subscribes to relevant output events served by other nodes in their server role. 
 *
 * @section SecIodeviceNDev2 Protocol Details
 *
 * The protocol for commands and notification is libFAUDES-token based and can be inspected eg via nc 
 * or telnet;  see the shell script in the tutorial. 
 * Event notifications are sent spontaneous to all connected clients in the format 
 * <tt>\<Notify\> Ev \</Notify\></tt>.
 * Commands are accepted in the format <tt>\<Cmd\> Command \</Cmd\></tt> and will be
 * answered accordingly.
 *
 * <table valign="top">
 * <tr>
 * <td> Command via TCP</td>
 * <td> Reply </td>
 * </tr>
 * <tr>
 * <td>  <tt>\<Cmd\> Info  \</Cmd\></tt> </td>
 * <td> configuration of node as token string  (<tt>\<SimplenetDevice name="SimpleMachine"\> ... 
 *      \</SimplenetDevice\> </tt> ) </td>
 * </tr>
 * <tr>
 * <td> <tt>\<Cmd\> Status  \</Cmd\></tt>  </td>
 * <td> acknowledgement with status string (<tt>\<Ack\> Up \</Ack\></tt>, 
 * <tt>\<Ack\> StartUp \</Ack\></tt> or <tt>\<Ack\> ShutDown \</Ack\></tt>, respectively; 
 * will not connect/reply while Down) </td>
 * </tr>
 * <tr>
 * <td> <tt>\<Cmd\> ResetRequest  \</Cmd\></tt>  </td>
 * <td> no acknowledgement </td>
 * </tr>
 * <tr>
 * <td> <tt>\<Subscribe\> Ev_1 ... Ev_N  \</Subscribe\></tt> </td>
 * <td> subset of available events (e.g. <tt>\<Subscribed\> Ev_2 Ev_7 Ev_9  \</Subscribed\></tt>)</td>
 * </tr>
 * </table>
 *
 * A minimal alternative implementation for a node consists of (1) a TCP server that ignores all
 * incomming messages and issues event notifications to any relevant events; and, (2) a TCP client 
 * that subscribes to all events and then listens to event notifications. All other commands are 
 * optional and may change in future revisions of this protocol. 
 *
 * @section SecIodeviceNDev3 Name Resolution
 *
 * On the technical side, each node needs to figure the IP addresses incl TCP ports on which the 
 * other nodes provide their service. To ease configuration, this information is distributed by 
 * UDP datagrams. In order to locate the other nodes within the network, a node may  broadcasts a 
 * network <em>request</em> datagramm. Each node that receives such a request, replies with an 
 * <em>advert</em> datagramm to provide its address. Thus, the simple net nodes rely on some 
 * underlying name resolution by DNS services, but node configuration itself refers to simple-net node names
 * only. Since each node knows about the names of all participating nodes, each node will know when 
 * all connections are up. 
 *
 * By default, UDP broadcasts are addressed to 255.255.255.255:40000. Since
 * routers are not meant to pass-on broadcasts, nDevice name resolution is restricted to 
 * one subnet. If the local host is connected to multiple subnets, you need to specify the
 * relevant subset explicitly by setting the appropriate broadcast address, e.g. 192.168.2.255:40000.
 * To restrict networks to the local machine, set the broadcast address to the loopback device
 * 127.0.0.1:40000. To span a network accross multiple subnets, server addresses can be 
 * explicitly specified as an attribute in the node configuration;
 * e.g. <tt> \<Node\> name=\"SimpleSupervisor\" address=\"192.168.2.1:40000\"\</Node\></tt>.
 * This is also the preferred
 * fallback when address resolution fails for other reasons.
 * 
 * <table valign="top">
 * <tr>
 * <td> Broadcast via UDP</td>
 * <td> Reply </td>
 * </tr>
 * <tr>
 * <td> <tt>\<Request\> network reqnode  \</Request\></tt> </td>
 * <td> advertisement of networkname, nodename and ip-address:port, e.g.,  
 * <tt> \<Advert\> SimpleLoop SimpleSupervisor 192.168.2.1:40000 \</Advert\></tt>
 * </td>
 * </tr>
 * </table>
 * <p>
 *
 * @section SecIodeviceNDev4 File IO
 *
 * For token IO, the nDevice reads and writes a section with label  
 * "SimplenetDevice". There are no relevant attributes yet. Simple machine example:
 *
 * @code
 * <SimplenetDevice name="SimpleMachine"> 
 *
 * <!-- Time scale in ms/ftiu -->
 * <TimeScale value="1000"/> 
 *
 * <!-- IP address of this node, incl. server TCP port -->
 * <ServerAddress value="localhost:40000"/> 

 * <!-- Broadcaset address for node resolution (optional)
 * <BroadcastAddress value="255.255.255.255:40000"/> 
 *
 * <!-- Network topology -->
 * <Network name="SimpleLoop"> 
 * <Node name="SimpleMachine"/> 
 * <Node name="SimpleSupervisor"/> 
 * </Network> 
 *
 * <!-- Event configuration -->
 * <EventConfiguration> 
 * <Event name="alpha" iotype="input"/> 
 * <Event name="beta" iotype="output"/> 
 * <Event name="mue" iotype="output"/> 
 * <Event name="lambda" iotype="input"/> 
 * </EventConfiguration> 
 *
 * </SimplenetDevice> 
 * @endcode
 *
 * @section SecIodeviceNDev5 Implementation Notes
 *
 * The current status of the code is premature; network io
 * assumes reasonably large buffers; thread/select mechanism is inefficient; 
 * exception handling wont work; etc etc
 * 
 *
 * @ingroup IODevicePlugin 
 */

class FAUDES_API nDevice : public vDevice {    

FAUDES_TYPE_DECLARATION(SimplenetDevice,nDevice,vDevice)

  // provide all access to background tasks
  friend void* NDeviceListen(void*);
  friend void* NDeviceServer(void*);
  friend void* NDeviceReply(void*);

 public:
  /**
   * Default constructor
   */
  nDevice(void);

  /**
   * Explicit destructor.
   */
  virtual ~nDevice(void);

  /**
   * Clear all configuration.
   * This implies Stop().
   */
  virtual void Clear(void);

  /**
   * Set server address of this node.
   * Note: you can only set th server address while the
   * device is down.
   *
   * @param rAddr 
   *   Address on which to run this server, e.g. "localhost:40000"
   * @exception Exception
   *   - No valid address (id 551) (NOT IMPLEMENTED)
   */
  void ServerAddress(const std::string& rAddr);

  /**
   * Set broadcast address for address resolution
   * Note: you can only set the broadcast address while the
   * device is down.
   *
   * @param rAddr 
   *   Address for UDP broadcasts e.g. "255.255.255.255:40000"
   * @exception Exception
   *   - No valid address (id 551) (NOT IMPLEMENTED)
   */
  void BroadcastAddress(const std::string& rAddr);

  /**
   * Set network name to participate.
   * Note: you can only set the network name 
   * while the device is down.
   *
   * @param rNetwork 
   *   Name of network, e.g. "ElevatorNetwork"
   */
  void NetworkName(const std::string& rNetwork);

  /**
   * Add a node to the network configuration.
   * Note: you can only configure the network
   * while the device is down.
   *
   * @param rNodeName 
   *   Node to participate in wthe network.
   */
  void InsNode(const std::string& rNodeName);

  /**
   * Add entry to node name resolution
   *
   * Note: you can only configure the network
   * while the device is down.
   * @param rNode
   *   Name of node to register
   * @param rAddress 
   *  Address incl port 
   */
  void InsNodeAddress(const std::string& rNode, const std::string& rAddress);
 

  /**
   * Add a node to the network configuration.
   * Note: you can only configure the network
   * while the device is down.
   *
   */
  void ClearNodes(void);

  /**
   * Insert event as input event.
   * Note: you can only configure events
   * while the device is down.
   *
   * @param event
   *   Event by name.
   */
  void InsInputEvent(const std::string& event);


  /**
   * Insert event as output event.
   * Note: you can only configure event
   * while the device is down.
   *
   * @param event
   *   Event by name.
   */
  void InsOutputEvent(const std::string& event);


  /**
   * Set up internal data structures
   *
   */
  virtual void Compile(void);


  /**
   * Activate the device. This function enables output execution and input reading.
   * It starts the background thread for incomming connections and tries to connect to relevant servers.
   *
   * @exception Exception
   *   - Not yet configured  (id 551)
   *   - Fatal network error (id 553)
   *   - Fatal thread error  (id 554)
   */
  virtual void Start(void);

  /**
   * Deactivate the device. This function disables output execution and input reading.
   * It stops the backhround thread to provide connections and disconnects from any servers.
   */
  virtual void Stop(void);

  /**
   * Reset device. Resets buffered input events and current time.
   *
   */
  virtual void Reset(void);

  /**
   * Run output command.
   *
   * @exception Exception
   *   - unknown output event (id 65)
   */
  virtual void WriteOutput(Idx output);



protected:

  /**
   * Actual method to read device configuration from tokenreader.
   *
   * This method calls the base class to read the device name and the
   * the timescale. It then reads address, networkid and nodes.
   * Overall device configuration is consists of DoReadPreface,
   * DoReadConfiguration and Compile. It isimplemented in vDevice.
   * The label and context parameters are ignored.
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information
   *
   * @exception Exception
   *   - IO error (id 1)
   */
  virtual void DoReadPreface(TokenReader& rTr,  const std::string& rLabel = "", const Type* pContext=0);
 
  /**
   * Actual method to write the device configuration to a TokenWriter.
   *
   * This method calls the base class vDevice to write the device name and
   * the time scale. It then writes network related data. The label and
   * context parameters are ignored.
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Read context to provide contextual information
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoWritePreface(TokenWriter& rTw, const std::string& rLabel="", const Type* pContext=0) const;


  /** Overall configuration (with actual type) */
  TaNameSet<AttributeSimplenetEvent>* pConfiguration ;

  /** Simplenet: network id */
  std::string mNetwork;

  /** Simplenet: address of my server incl port (localhost:40000)*/
  SimplenetAddress mListenAddress;

  /** Simplenet: address for udp broadcast (255.255.255.255:40000*/
  SimplenetAddress mBroadcastAddress;

  /** Simplenet: effective address of my server port */
  SimplenetAddress mEffectiveListenAddress;

  /** Simplenet: list of nodes in this network incl default addresses*/
  std::map<std::string,std::string> mNetworkNodes;  
  
  /** Compiled data: map subscriptions */
  std::map<std::string,EventSet> mInputSubscriptions;

  /** Background: mutex for below shared variables*/
  faudes_mutex_t mMutex;

  /** Background: thread handle (global) */
  faudes_thread_t mThreadListen; 

  /** Background: request to join via flag (mutexed) */
  bool mStopListen;

  /** Background: server socket to listen (background only) */
  int mListenSocket;
  
  /** Background: udp broadcast socket (background only) */
  int mBroadcastSocket;
  
  /** Background: state of a connection to a client (shared) */
  typedef struct {
    int  mClientSocket;      // the socket the client is connected to
    EventSet mEvents;        // events the client has subscribed to 
    bool mConnected;         // set to true, if a subscription has been seen
    std::string mLineBuffer; // buffer to receive one line
  } ClientState;  

  /** Background: map sockets to connection states (shared) */
  std::map<int, ClientState> mOutputClientStates;

  /** Background: state of a connection to an event server (shared)*/
  typedef struct {
    SimplenetAddress mAddress;        // actual IP address incl TCP port of remote server
    SimplenetAddress mDefaultAddress; // default IP address incl TCP port of remote server
    EventSet mEvents;                 // events we have subscribed to
    int  mServerSocket;               // socket used to connect with provider
    std::string mLineBuffer;          // buffer to receive one line
  } ServerState;  

  /** Background: connection states to event servers (by node name)*/
  std::map<std::string,ServerState> mInputServerStates;



}; // end class nDevice

// declare background threads
void* NDeviceListen(void*);

#endif // configured for simplenet



} // namespace faudes

#endif // include
