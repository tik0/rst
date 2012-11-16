/* This file is generated - do not edit. */

#include "MixtureOfGaussian1D.pb.h"


DEFINE_MECHANISM(MechanismRosMsg);
DEFINE_WIRE_SCHEMA(rststochasticsMixtureOfGaussian1D,rst.stochastics.MixtureOfGaussian1D);
DEFINE_WIRE_SCHEMA(rststochasticsMixtureOfGaussian1DGaussianComponent1D,rst.stochastics.MixtureOfGaussian1D.GaussianComponent1D);

// Type-independent protocol buffer API for rst::stochastics::mixtureOfGaussian1D::GaussianComponent1D

 const rst::stochastics::MixtureOfGaussian1D::GaussianComponent1D& rst::stochastics::MixtureOfGaussian1D::GaussianComponent1D::default_instance(){
  static rst::stochastics::MixtureOfGaussian1D::GaussianComponent1D*instance=NULL;
  if(!instance)instance=new GaussianComponent1D();
  return *instance;
}

 const std::string rst::stochastics::MixtureOfGaussian1D::GaussianComponent1D::GetTypeName(){
  return "rst.stochastics.mixtureOfGaussian1D.GaussianComponent1D";
}

rst::stochastics::MixtureOfGaussian1D::GaussianComponent1D* rst::stochastics::MixtureOfGaussian1D::GaussianComponent1D::New(){
  return new rst::stochastics::MixtureOfGaussian1D::GaussianComponent1D();
}

int rst::stochastics::MixtureOfGaussian1D::GaussianComponent1D::ByteSize() const{
  return rosetta::packedSize<rosetta::MechanismRosMsg,rosetta::rststochasticsMixtureOfGaussian1DGaussianComponent1D>(*this);

}

bool rst::stochastics::MixtureOfGaussian1D::GaussianComponent1D::SerializeToString(std::string* destination) const{
  std::vector<unsigned char> temp(rosetta::packedSize<rosetta::MechanismRosMsg,rosetta::rststochasticsMixtureOfGaussian1DGaussianComponent1D>(*this));
  rosetta::pack<rosetta::MechanismRosMsg,rosetta::rststochasticsMixtureOfGaussian1DGaussianComponent1D>(*this,temp,0,temp.size());
  destination->resize(temp.size());
  std::copy((char*)&temp[0],(char*)(&temp[0]+temp.size()),
  destination->begin());
  return true;
  

}

bool rst::stochastics::MixtureOfGaussian1D::GaussianComponent1D::ParseFromString(const std::string& source){
  std::vector<unsigned char> temp((unsigned char*)&source[0],
  (unsigned char*)(&source[0]+source.size()));
  rosetta::unpack<rosetta::MechanismRosMsg,rosetta::rststochasticsMixtureOfGaussian1DGaussianComponent1D>(temp,*this,0,temp.size());
  return true;
  

}



bool rst::stochastics::MixtureOfGaussian1D::GaussianComponent1D::SerializeToArray(void* destination,int size) const{
  std::vector<unsigned char> temp(size);
  rosetta::pack<rosetta::MechanismRosMsg,rosetta::rststochasticsMixtureOfGaussian1DGaussianComponent1D>(*this,temp,0,size);
  std::copy(temp.begin(),temp.end(),(char*)destination);
  return true;
  

}

bool rst::stochastics::MixtureOfGaussian1D::GaussianComponent1D::ParseFromArray(const void* source,int size){
  std::vector<unsigned char> temp((unsigned char*)source,(unsigned char*)source+size);
  rosetta::unpack<rosetta::MechanismRosMsg,rosetta::rststochasticsMixtureOfGaussian1DGaussianComponent1D>(temp,*this,0,size);
  return true;
  

}



// Type-independent protocol buffer API for rst::stochastics::MixtureOfGaussian1D

 const rst::stochastics::MixtureOfGaussian1D& rst::stochastics::MixtureOfGaussian1D::default_instance(){
  static rst::stochastics::MixtureOfGaussian1D*instance=NULL;
  if(!instance)instance=new MixtureOfGaussian1D();
  return *instance;
}

 const std::string rst::stochastics::MixtureOfGaussian1D::GetTypeName(){
  return "rst.stochastics.MixtureOfGaussian1D";
}

rst::stochastics::MixtureOfGaussian1D* rst::stochastics::MixtureOfGaussian1D::New(){
  return new rst::stochastics::MixtureOfGaussian1D();
}

int rst::stochastics::MixtureOfGaussian1D::ByteSize() const{
  return rosetta::packedSize<rosetta::MechanismRosMsg,rosetta::rststochasticsMixtureOfGaussian1D>(*this);

}

bool rst::stochastics::MixtureOfGaussian1D::SerializeToString(std::string* destination) const{
  std::vector<unsigned char> temp(rosetta::packedSize<rosetta::MechanismRosMsg,rosetta::rststochasticsMixtureOfGaussian1D>(*this));
  rosetta::pack<rosetta::MechanismRosMsg,rosetta::rststochasticsMixtureOfGaussian1D>(*this,temp,0,temp.size());
  destination->resize(temp.size());
  std::copy((char*)&temp[0],(char*)(&temp[0]+temp.size()),
  destination->begin());
  return true;
  

}

bool rst::stochastics::MixtureOfGaussian1D::ParseFromString(const std::string& source){
  std::vector<unsigned char> temp((unsigned char*)&source[0],
  (unsigned char*)(&source[0]+source.size()));
  rosetta::unpack<rosetta::MechanismRosMsg,rosetta::rststochasticsMixtureOfGaussian1D>(temp,*this,0,temp.size());
  return true;
  

}



bool rst::stochastics::MixtureOfGaussian1D::SerializeToArray(void* destination,int size) const{
  std::vector<unsigned char> temp(size);
  rosetta::pack<rosetta::MechanismRosMsg,rosetta::rststochasticsMixtureOfGaussian1D>(*this,temp,0,size);
  std::copy(temp.begin(),temp.end(),(char*)destination);
  return true;
  

}

bool rst::stochastics::MixtureOfGaussian1D::ParseFromArray(const void* source,int size){
  std::vector<unsigned char> temp((unsigned char*)source,(unsigned char*)source+size);
  rosetta::unpack<rosetta::MechanismRosMsg,rosetta::rststochasticsMixtureOfGaussian1D>(temp,*this,0,size);
  return true;
  

}


