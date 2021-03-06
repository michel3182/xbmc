/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

/*!
\file GUISpinControl.h
\brief
*/

#include <vector>

#include "GUIControl.h"
#include "GUITexture.h"
#include "GUILabel.h"

#define SPIN_CONTROL_TYPE_INT    1
#define SPIN_CONTROL_TYPE_FLOAT  2
#define SPIN_CONTROL_TYPE_TEXT   3
#define SPIN_CONTROL_TYPE_PAGE   4

/*!
 \ingroup controls
 \brief
 */
class CGUISpinControl : public CGUIControl
{
public:
  CGUISpinControl(int parentID, int controlID, float posX, float posY, float width, float height, const CTextureInfo& textureUp, const CTextureInfo& textureDown, const CTextureInfo& textureUpFocus, const CTextureInfo& textureDownFocus, const CTextureInfo& textureUpDisabled, const CTextureInfo& textureDownDisabled, const CLabelInfo& labelInfo, int iType);
  ~CGUISpinControl(void) override;
  CGUISpinControl *Clone() const override { return new CGUISpinControl(*this); };

  void Process(unsigned int currentTime, CDirtyRegionList &dirtyregions) override;
  void Render() override;
  bool OnAction(const CAction &action) override;
  void OnLeft() override;
  void OnRight() override;
  bool HitTest(const CPoint &point) const override;
  bool OnMouseOver(const CPoint &point) override;
  bool OnMessage(CGUIMessage& message) override;
  void AllocResources() override;
  void FreeResources(bool immediately = false) override;
  void DynamicResourceAlloc(bool bOnOff) override;
  void SetInvalid() override;
  void SetPosition(float posX, float posY) override;
  float GetWidth() const override;
  void SetRange(int iStart, int iEnd);
  void SetFloatRange(float fStart, float fEnd);
  void SetValue(int iValue);
  void SetValueFromLabel(const std::string &label);
  void SetFloatValue(float fValue);
  void SetStringValue(const std::string& strValue);
  int GetValue() const;
  float GetFloatValue() const;
  std::string GetStringValue() const;
  void AddLabel(const std::string& strLabel, int iValue);
  void AddLabel(const std::string& strLabel, const std::string& strValue);
  const std::string GetLabel() const;
  void SetReverse(bool bOnOff);
  int GetMaximum() const;
  int GetMinimum() const;
  void SetSpinAlign(uint32_t align, float offsetX) { m_label.GetLabelInfo().align = align; m_label.GetLabelInfo().offsetX = offsetX; };
  void SetType(int iType) { m_iType = iType; };
  float GetSpinWidth() const { return m_imgspinUp.GetWidth(); };
  float GetSpinHeight() const { return m_imgspinUp.GetHeight(); };
  void SetFloatInterval(float fInterval);
  void SetShowRange(bool bOnoff) ;
  void SetShowOnePage(bool showOnePage) { m_showOnePage = showOnePage; };
  void Clear();
  std::string GetDescription() const override;
  bool IsFocusedOnUp() const;

  bool IsVisible() const override;

protected:
  EVENT_RESULT OnMouseEvent(const CPoint &point, const CMouseEvent &event) override;
  bool UpdateColors() override;
  /*! \brief Render the spinner text
   \param posX position of the left edge of the text
   \param posY positing of the top edge of the text
   \param width width of the text
   \param height height of the text
   */
  virtual void RenderText(float posX, float posY, float width, float height);
  CGUILabel::COLOR GetTextColor() const;
  void PageUp();
  void PageDown();
  bool CanMoveDown(bool bTestReverse = true);
  bool CanMoveUp(bool bTestReverse = true);
  void MoveUp(bool bTestReverse = true);
  void MoveDown(bool bTestReverse = true);
  void ChangePage(int amount);
  int m_iStart;
  int m_iEnd;
  float m_fStart;
  float m_fEnd;
  int m_iValue;
  float m_fValue;
  int m_iType;
  int m_iSelect;
  bool m_bReverse;
  float m_fInterval;
  std::vector<std::string> m_vecLabels;
  std::vector<int> m_vecValues;
  std::vector<std::string> m_vecStrValues;
  CGUITexture m_imgspinUp;
  CGUITexture m_imgspinDown;
  CGUITexture m_imgspinUpFocus;
  CGUITexture m_imgspinDownFocus;
  CGUITexture m_imgspinUpDisabled;
  CGUITexture m_imgspinDownDisabled;
  CGUILabel   m_label;
  bool m_bShowRange;
  char m_szTyped[10];
  int m_iTypedPos;

  int m_currentItem;
  int m_itemsPerPage;
  int m_numItems;
  bool m_showOnePage;
};

