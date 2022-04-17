import voice_acquisition
import voice_idenfity
import voice_play
import voice_synthesis
import IntelligentConcersation

while True:
    voice_acquisition.rec()
    ret = voice_idenfity.listen()
    msg = IntelligentConcersation.robot(ret)
    voice_synthesis.tencent_cloud_com(msg)
    voice_play.play()

