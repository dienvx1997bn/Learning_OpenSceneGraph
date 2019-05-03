#include <osg/Switch>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>


class AnimatingSwitch : public osg::Switch
{
    public:
    AnimatingSwitch() : osg::Switch(), _count(0) {}
    AnimatingSwitch( const AnimatingSwitch& copy,const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY ): osg::Switch(copy, copyop), _count(copy._count) {}
    META_Node( osg, AnimatingSwitch );
    virtual void traverse( osg::NodeVisitor& nv );
    protected:
    unsigned int _count;
};

void AnimatingSwitch::traverse( osg::NodeVisitor& nv )
{
    if ( !((++_count)%100) )
    {
        setValue( 0, !getValue(0) );
        setValue( 1, !getValue(1) );
    }
    osg::Switch::traverse( nv );
}

int main(int argc, char *argv[])
{

    osg::ref_ptr<osg::Node> model1= osgDB::readNodeFile("/home/diennv2/Desktop/DataOSG_3.0/cessna.osg");
    osg::ref_ptr<osg::Node> model2= osgDB::readNodeFile("/home/diennv2/Desktop/DataOSG_3.0/cessnafire.osg");
    osg::ref_ptr<AnimatingSwitch> root = new AnimatingSwitch;
    root->addChild( model1.get(), true );
    root->addChild( model2.get(), false );

    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    return viewer.run();

}

