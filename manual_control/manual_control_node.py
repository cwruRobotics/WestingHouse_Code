import rospy
from std_msg.msg import UInt16

LBM_Publisher=rospy.Publisher("motor_left_back", UInt16, queue_size=10)

RBM_Publisher=rospy.Publisher("motor_left_back", UInt16, queue_size=10)

LFM_Publisher=rospy.Publisher("motor_left_back", UInt16, queue_size=10)

RFM_Publisher=rospy.Publisher("motor_left_back", UInt16, queue_size=10)


def setLBM_Power(power):
    LBM_Publisher.publish(power)

def setRBM_Power(power):
    RBM_Publisher.publish(power)
def setLFM_Power(power):
    LFM_Publisher.publish(power)

def setRFM_Power(power):
    RFM_Publisher.publish(power)


rospy.init_node("manual_control", anonymous=True )

while not rospy.is_shutdown(){


}
