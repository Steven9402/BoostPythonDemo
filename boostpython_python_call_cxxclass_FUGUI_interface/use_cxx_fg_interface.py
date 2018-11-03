import CalculateSkuidNum

# 初始化算法库，加载模型
mym=CalculateSkuidNum.CalculateSkuidNum(0)

# 开始信号由你们定，为"start"开启线程
# 
print mym.start() 

# 结束信号由你们定
print mym.stop()

SkuidList=mym.getSkuid()
SkuNumList=mym.getSkuNum()
for i in range(len(SkuidList)):
    print 'SKU_ID = ',SkuidList[i]
    print 'SKU_NUM = ',SkuNumList[i]
    print '-------'


