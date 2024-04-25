# Benchmark

For instruction, see help. (./benchmark_model --help)

Ex)  
For CPU FP32 (4-threads)  
./benchmark_model --graph=./model/ssd_mobilenet_v1.tflite --num_threads=4

For GPU FP32  
./benchmark_model --graph=./model/ssd_mobilenet_v1.tflite --num_threads=4 --use_gpu=1

For CPU INT8 (4-threads)  
./benchmark_model --graph=./model/ssd_mobilenet_v1_quant.tflite --num_threads=4

For Hexagon (4-threads)  
./benchmark_model --graph=./model/ssd_mobilenet_v1_quant.tflite --num_threads=4 --use_hexagon=1



# Image labeling application

For instruction, see help. (./label_image --help)

Ex)  
./label_image -i ./image/grace_hopper.bmp -l ./label/labels.txt -m ./model/ssd_mobilenet_v1.tflite -t 4
