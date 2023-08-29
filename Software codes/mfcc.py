
import speaker_verification_toolkit.tools as svt
import librosa
data,sr = librosa.load('Hello',sr=16000,mono=True)
data = svt.rms_silence_filter(data)
data = svt.extract_mfcc(data)
print("The MFCC values are : \n",data)
