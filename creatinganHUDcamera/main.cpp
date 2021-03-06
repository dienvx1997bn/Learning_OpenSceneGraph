#include <osg/Camera>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osg/MatrixTransform>


int main(int argc, char *argv[])
{
    osg::ref_ptr<osg::Node> model = osgDB::readNodeFile("/home/diennv2/Desktop/DataOSG_3.0/lz.osg");
    osg::ref_ptr<osg::Node> hud_model = osgDB::readNodeFile("/home/diennv2/Desktop/DataOSG_3.0/cessna.osg" );

//    osg::ref_ptr<osg::Camera> camera = new osg::Camera;
//    camera->setClearMask( GL_DEPTH_BUFFER_BIT );
//    camera->setRenderOrder( osg::Camera::POST_RENDER );

//    camera->setReferenceFrame( osg::Camera::ABSOLUTE_RF );
//    camera->setViewMatrixAsLookAt(
//    osg::Vec3(0.0f,-5.0f,5.0f), osg::Vec3(),
//    osg::Vec3(0.0f,1.0f,1.0f)
//    );
//    camera->addChild( hud_model.get() );

    osg::ref_ptr<osg::MatrixTransform> transform1 = new osg::MatrixTransform;
    transform1->setMatrix( osg::Matrix::translate(
    0.0f, 0.0f, 400.0f) );
    transform1->addChild( hud_model.get() );


    osg::ref_ptr<osg::Group> root = new osg::Group;
    root->addChild( model.get() );
//    root->addChild(camera.get());
    root->addChild(transform1.get());

    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    return viewer.run();
}

